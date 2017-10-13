#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include"zmalloc.h"


void zlibc_free(void *ptr){
	free(ptr);
}

#define PREFIX_SIZE (sizeof(size_t))

#define update_zmalloc_stat_add(__n) do{\
	pthread_mutex_lock(&used_memory_mutex);\
	used_memory += (__n);\
	pthread_mutex_unlock(&used_memory_mutex);\
}while(0)

#define update_zmalloc_stat_sub(__n) do{\
	pthread_mutex_lock(&used_memory_mutex);\
	used_memory -= (__n);\
	pthread_mutex_unlock(&used_memory_mutex);\
}while(0)

#define update_zmalloc_stat_alloc(__n)do{\
	size_t _n = (__n);\
	if(_n&(sizeof(long)-1)) _n += sizeof(long)-(_n&(sizeof(long)-1));\
	if(zmalloc_thread_safe){\
		update_zmalloc_stat_add(_n);\
	}else{\
		used_memory += _n;\
	}\
}while(0)

#define update_zmalloc_stat_free(__n)do{\
	size_t _n = (__n);\
	if(_n&(sizeof(long)-1)) _n += sizeof(long)-(_n&(sizeof(long)-1));\
	if(zmalloc_thread_safe){\
		update_zmalloc_stat_sub(_n);\
	}else{\
		used_memory -= _n;\
	}\
}while(0)

static size_t used_memory = 0;
static int zmalloc_thread_safe = 0;

pthread_mutex_t used_memory_mutex = PTHREAD_MUTEX_INITIALIZER;

static void zmalloc_default_oom(size_t size){
	fprintf(stderr,"zmalloc: Out od memory trying to allocate %zu bytes\n",size);
	fflush(stderr);
	abort();
}

static void (*zmalloc_oom_handler)(size_t) = zmalloc_default_oom;

void *zmalloc(size_t size){
	void *ptr = malloc(size+PREFIX_SIZE);
	if (!ptr){
		zmalloc_oom_handler(size);
	}
	update_zmalloc_stat_alloc(zmalloc_size(ptr));
	return ptr;
}

void *zcalloc(size_t size){
	void *ptr = calloc(1,size+PREFIX_SIZE);

	if (!ptr){
		zmalloc_oom_handler(size);
	}
	update_zmalloc_stat_alloc(zmalloc_size(ptr));
	return ptr;
}

void *zrealloc(void *ptr,size_t size){
	void *realptr;
	size_t oldsize;
	void *newptr;

	if(ptr == NULL)return zmalloc(size);
	oldsize = zmalloc_size(ptr);
	newptr = realloc(ptr,size);
	if(!newptr)zmalloc_oom_handler(size);

	update_zmalloc_stat_free(oldsize);
	update_zmalloc_stat_alloc(zmalloc_size(newptr));
}

size_t zmalloc_size(void *ptr){
	void *realptr = (char*)ptr-PREFIX_SIZE;
	size_t size = *((size_t*)realptr);

	if(size&(sizeof(long)-1)) size += sizeof(long)-(size&(sizeof(long)-1));
	return size+PREFIX_SIZE;
}

void zfree(void *ptr){
	if(ptr == NULL)return;
	update_zmalloc_stat_free(zmalloc_size(ptr));
	free(ptr);
}

char *zstrdup(const char *s){
	size_t l= strlen(s)+1;
	char *p = (char*)zmalloc(l);

	memcpy(p,s,l);
	return p;
}

size_t zmalloc_used_memory(void){
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

void zmalloc_enable_thread_safeness(void){
	zmalloc_thread_safe = 1;
}

void zmalloc_set_oom_handler(void (*oom_handler)(size_t)){
	zmalloc_oom_handler = oom_handler;
}

size_t zmalloc_get_rss(void){
	return zmalloc_used_memory();
}

float zmalloc_get_fragmentation_ratio(void){
	return (float)zmalloc_get_rss()/zmalloc_used_memory();
}

size_t zmalloc_get_private_dirty(void){
	return 0;
}


