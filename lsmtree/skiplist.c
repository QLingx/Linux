#include<string.h>
#include "skiplist.h"

#define cmp_lt(a,b) (strcmp(a,b)<0)
#define cmp_eq(a,b) (strcmp(a,b)==0)

#define NIL list->hdr

struct pool{
    struct pool *next;
    char *ptr;
    unsigned int rem;
};

static struct pool *pool_new(size_t size){
    struct pool *pool = malloc(sizeof(struct pool));
    pool->next = NULL;
    pool->ptr = malloc(size);

    return pool;
}

static void pool_destory(struct pool *pool){
    while(pool->next != NULL){
        struct pool *next = pool->next;
        free(pool->ptr);
        free(pool);
        pool = next;
    }
}

static void *pool_alloc(skiplist *list,size_t size){
    struct pool *pool = pool_new(size);
    pool->next = list->pool;
    list->pool = pool;
    return pool->ptr;
}

skiplist* skiplist_new(size_t size){
    skiplist *list = malloc(sizeof(skiplist));
    list->hdr = malloc(sizeof(skipnode) + MAXLEVEL*sizeof(skipnode*));

    for(int i = 0;i <= MAXLEVEL;i++){
        list->hdr->forword[i] = NIL;
    }
    list->level = 0;
    list->size = size;
    list->count = 0;
    list->pool = (struct pool *) list->pool_embedded;
    list->pool->next = NULL;
    return list;
}

void skiplist_free(skiplist *list){
    pool_destory(list->pool);
    free(list->hdr);
    free(list);
}

int skiplist_notfull(skiplist *list){
    if(list->count < list->size){
        return 1;
    }
    return 0;
}

int skiplist_insert(skiplist *list,slice *sk,UINT val,OPT opt){
    skipnode *update[MAXLEVEL+1];
    skipnode *x;

    char *key = sk->data;

    if(skiplist_notfull(list)){
        return 0;
    }

    x = list->hdr;
    for(int i = list->level;i >= 0;i--){
        while(x->forword[i] != NIL && cmp_lt(x->forword[i]->key,key)){
            x = x->forword[i];
        }
        update[i] = x;
    }
}