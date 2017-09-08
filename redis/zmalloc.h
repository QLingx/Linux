/*
 * zmalloc.h
 *
 *  Created on: Dec 27, 2016
 *      Author: pengcong
 */

#ifndef ZMALLOC_H_
#define ZMALLOC_H_

void *zmalloc(size_t size);
void *zcalloc(size_t size);
void *zrealloc(void *ptr,size_t size);
void zfree(void *ptr);
void *zstrdup(const char *s);
size_t zmalloc_used_memory(void);
void zmalloc_enable_thread_safness(void);
void zmalloc_set_oom_handler(void (*oom_handler)(size_t));
float zmalloc_get_fragmentation_ratio(void);
size_t zmalloc_get_rss(void);
size_t zmalloc_get_private_dirty(void);
void zlibc_free(void *ptr);
size_t zmalloc_size(void *ptr);



#endif /* ZMALLOC_H_ */
