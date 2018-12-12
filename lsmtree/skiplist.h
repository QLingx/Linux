#ifndef SKIPLIST_H
#define SKIPLIST_H

#include<stdlib.h>
#include "util.h"
#include "platform.h"

#define MAXLEVEL (15)
#define SKIP_KSIZE (256)

typedef enum {ADD,DEL} OPT;

typedef struct skipnode_t{
    char key[SKIP_KSIZE];
    UINT val;
    OPT opt;
    skipnode *forword[1];
    skipnode *next;
}skipnode;

typedef struct skiplist_t{
    skipnode *hdr;
    size_t count;
    size_t size;
    int level;
    char pool_embedded[1024];
    struct pool *pool;
}skiplist;

skiplist* skiplist_new(size_t size);
void skip_init(skiplist *list);
int skip_insert(skiplist *list,slice *sk,UINT val,OPT opt);
int skip_notfull(skiplist *list);
void skiplist_dump(skiplist *list);
void skiplist_free(skiplist *list); 

#endif