/*
 * zmalloc.c
 *
 *  Created on: Dec 27, 2016
 *      Author: pengcong
 */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include "zmalloc.h"

static int zmalloc_thread_safe = 0;
static size_t used_memory = 0;
pthread_mutex_t used_memory_mutex = PTHREAD_MUTEX_INITIALIZER;

#define PREFIX_SIZE (sizeof(size_t))

#define update_zmalloc_stat_add(__n) do {\
	pthread_mutex_lock(&used_memory_mutex);\
	used_memory += (__n);\
	pthread_mutex_unlock(&used_memory_mutex);\
}while(0)

#define update_zmalloc_stat_sub(__n) do {\
	pthread_mutex_lock(&used_memory_mutex);\
	used_memory -= (__n);\
	pthread_mutex_unlock(&used_memory_mutex);\
}while(0)

#define update_zmalloc_stat_alloc(__n) do{\
	size_t _n = (__n);\
	if(_n&(sizeof(long)-1)){_n += sizeof(long)-(_n&(sizeof(long)-1));}\
	if(zmalloc_thread_safe){\
		update_zmalloc_stat_add(_n);\
	}else{\
		used_memory += _n;\
	}\
}while(0)

#define update_zmalloc_stat_free(__n) do {\
	size_t _n = (__n);\
	if(_n&(sizeof(long)-1)){_n += sizeof(long)-(_n&(sizeof(long)-1));}\
	if(zmalloc_thread_safe){\
		update_zmalloc_stat_sub(_n);\
	}else{\
		used_memory -= _n;\
	}\
}while(0)

void zlibc_free(void *ptr)
{
	free(ptr);
}

size_t zmalloc_size(void *ptr)
{
	void *realptr = (char*)ptr - PREFIX_SIZE;
	size_t size = *((size_t*)realptr);
	if(size & (sizeof(long)-1)){
		size += sizeof(long)-(size&(sizeof(long)-1));
	}
	return size + PREFIX_SIZE;
}

static zmalloc_default_oom(size_t size)
{
	fprintf(stderr,"zmalloc: Out of memery trying to allocate %zu bytes\n",size);
	fflush(stderr);
	abort();
}

static void (*zmalloc_oom_handler)(size_t) = zmalloc_default_oom;

void zmalloc_set_oom_handler(void(*oom_handler)(size_t))
{
	zmalloc_oom_handler = oom_handler;
}

void *zmalloc(size_t size)
{
	void *ptr = malloc(size + PREFIX_SIZE);
	if(!ptr){
		zmalloc_oom_handler(size);
	}
	*((size_t*)ptr) = size;
	update_zmalloc_stat_alloc(zmalloc_size(ptr));
	return (char*)ptr + PREFIX_SIZE;
}
void *zcalloc(size_t size)
{
	void *ptr = calloc(1,size+PREFIX_SIZE);
	if(!ptr){
		zmalloc_oom_handler(size);
	}
	*((size_t*)ptr) = size;
	update_zmalloc_stat_alloc(size + PREFIX_SIZE);
	return (char*)ptr + PREFIX_SIZE;
}
void *zrealloc(void *ptr,size_t size)
{
	void *realptr;
	size_t oldsize;
	void *newptr;

	if(NULL == ptr){
		return zmalloc(size);
	}
	realptr = (char*)ptr - PREFIX_SIZE;
	oldsize = *((size_t*)realptr);
	newptr = realloc(ptr,size+PREFIX_SIZE);
	if(!newptr){
		zmalloc_oom_handler(size);
	}
	*((size_t*)newptr) = size;
	update_zmalloc_stat_free(oldsize);
	update_zmalloc_stat_alloc(size);
	return (char*)newptr + PREFIX_SIZE;
}
void zfree(void *ptr)
{
	void *realptr;
	size_t oldsize;
	if(ptr == NULL){
		return;
	}

	realptr = (char*)ptr - PREFIX_SIZE;
	oldsize = *((size_t*)realptr);
	update_zmalloc_stat_free(oldsize+PREFIX_SIZE);
	free(realptr);
}
void *zstrdup(const char *s)
{
	size_t l = strlen(s)+1;
	char *p = zmalloc(l);
	memcpy(p,s,l);
	return p;
}
size_t zmalloc_used_memory(void)
{
	size_t um;
	if(zmalloc_thread_safe){
		pthread_mutex_lock(&used_memory_mutex);
		um = used_memory;
		pthread_mutex_unlock(&used_memory_mutex);
	}else{
		um = used_memory;
	}
	return um;
}
void zmalloc_enable_thread_safness(void)
{
	zmalloc_thread_safe = 1;
}
float zmalloc_get_fragmentation_ratio(void)
{
	return (float)zmalloc_get_rss()/zmalloc_used_memory();
}
size_t zmalloc_get_rss(void)
{
	return zmalloc_used_memory();
}
size_t zmalloc_get_private_dirty(void)
{
	return 0;
}


int main()
{
	char *str = "glianyi";
	printf("%s",(char*)zstrdup(str));
	return 0;
}


