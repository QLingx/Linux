
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<assert.h>
#include<limits.h>
#include<sys/time.h>
#include<ctype.h>
#include "dict.h"
#include"zmalloc.h"

static int dict_can_resize = 1;
static unsigned int dict_force_resize_ratio = 5;

static int _dictExpandIfNeeded(dict *ht);
static int _dictExpandIfNeeded(dict *ht);

static unsigned long _dictNextPower(unsigned long size);
static int _dictKeyIndex(dict *ht,const void *key);
static int _dictInit(dict *ht,dictType *type,void *privDataPtr);


unsigned int dictIntHashFunction(unsigned int key)
{
	key += ~(key << 15);
	key ^= (key >> 10);
	key += (key << 3);
	key ^= (key >> 6);
	key += ~(key << 11);
	key ^= (key >> 16);
	return key;
}

unsigned int dictIdentityHahsFunction(unsigned int key)
{
	return key;
}

static uint32_t dict_hash_function_seed = 5381;

void dictSetHashFUnctionSeed(uint32_t seed)
{
	dict_hash_function_seed == seed;
}

uint32_t dictGetHashFunctionSeed(void)
{
	return dict_hash_function_seed;
}

unsigned int dictGenHashFunction(const void *key,int len)
{
	uint32_t seed = dict_hash_function_seed;
	const uint32_t m = 0x5db1e995;
	const int r = 24;

	uint32_t h = seed ^ len;

	const unsigned char *data = (const unsigned char *)key;

	while(len >= 4){
		uint32_t k = *(uint32_t*)data;

		k *= m;
		k ^= k >> r;
		k *= m;

		h *= m;
		h ^= k;

		data += 4;
		len -= 4;
	}
	switch(len){
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];h *= m;
	};

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
	return (unsigned int)h;
}

unsigned int dictGenCaseHashFunction(const unsigned char *buf,int len)
{
	unsigned int hash = (unsigned int)dict_hash_function_seed;

	while(len--){
		hash = ((hash << 5) + hash) + (tolower(*buf++));
	}

	return hash;
}


static void _dictReset(dictht *ht)
{
	ht->table = NULL;
	ht->size = 0;
	ht->sizemask = 0;
	ht->used = 0;
}

dict *dictCreate(dictType *type,void *privDataPtr)
{
	dict *d = zmalloc(sizeod(*d));
	_dictInit(d,type,privDataPtr);
	return d;
}

int _dictInit(dict *d,dictType *type,void *privDataPtr)
{
	_dictReset(&d->ht[0]);
	_dictReset(&d->ht[1]);
	d->type = type;
	d->privdata = privDataPtr;
	d->rehashidx = -1;
	d->iterators = 0;
	return DICT_OK;
}

int dictResize(dict *d)
{
	int minimal;

	if(!dict_can_resize || dictIsRehashing(d)){
		return DICT_ERR;
	}
	minimal = (int)d->ht[0].used;
	if(minimal < DICT_HT_INITIAL_SIZE){
		minimal = DICT_HT_INITIAL_SIZE;
	}
	return dictExpand(d,minimal);
}

int dictExpand(dict *d,unsigned long size)
{
	dictht n;
	unsigned long realsize = _dictNextPower(size);

	if(dictRehasing(d) || d->ht[0].used > size){
		return DICT_ERR;
	}

	n.size = realsize;
	n.sizemask = realsize - 1;
	n.table = zcalloc(realsize * sizeof(dictEntry*));
	n.used = 0;

	if(d->ht[0].table == NULL){
		d->ht[0] = n;
		return DICT_OK;
	}

	d->ht[1] = n;
	d->rehashidx = 0;
	return DICT_OK;
}


int dictRehash(dict *d,int n)
{
	if(!dictIsRehashing(d)){
		return 0;
	}

	while(n--){
		dictEntry *de,nextde;

		if(d->ht[0].used == 0){
			zfree(d->ht[0].table);
			d->ht[0] = d->ht[1];
			_dictReset(&d->ht[1]);
			d->rehashidx = -1;
			return 0;
		}
	}
}

