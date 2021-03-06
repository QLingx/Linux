/*
 * dict.h
 *
 *  Created on: Dec 29, 2016
 *      Author: pengcong
 */

#include<stdint.h>

#ifndef DICT_H_
#define DICT_H_

#define DICT_OK 0
#define DICT_ERR 1

#define DICT_NOTUSED(V) ((void)V)

typedef struct dictEntry{
	void *key;
	union{
		void *val;
		uint64_t u64;
		int64_t s64;
	} v;
	struct dictEntry *next;
} dictEntry;

typedef struct dicType{
	unsigned int (*hashFunction)(const void *key);
	void *(*keyDup)(void *privdata,const void *key);
	void *(*valDup)(void *privdata,const void *obj);
	int (*keyCompare)(void *privdata,const void *key1,const void *key2);
	void (*keyDestructor)(void *privdata,void *key);
	void (*valDestructor)(void *privdata,void *obj);
}dictType;

typedef struct dictht{
	dictEntry **table;
	unsigned long size;
	unsigned long sizemask;
	unsigned long used;
}dictht;

typedef struct dict{
	dictType *type;
	void *privdata;
	dictht ht[2];
	int rehashidx;
	int iterators;
}dict;

typedef struct dictIterator{
	dict *d;
	int table,index,safe;
	dictEntry *entry,*nextEntry;
}dictIterator;

#define DICT_HT_INITIAL_SIZE 4

#define dictFreeVal(d,entry)\
	if((d)->type->valDestructor){\
		(d)->type->valDestructor((d)->privdata,(entry)->v.val)\
	}

#define dictSetVal(d,entry,_val_) do {\
	if((d)->type->valDup){\
		entry->v.val = (d)->type->valDup((d)->privdata,_val_);\
	}else{\
		entry->v.val = (_val_);\
	}\
}while(0)

#define dictSetSignedIntegerVal(entry,_val_)\
		do{ entry->v.s64 = _val_; }while(0)

#define dictSetUnsignedIntegerVal(entry,_val_)\
		do { entry->v.u64 = _val_; }while(0)

#define dictFreeKey(d,entry)\
		if((d)->type->keyDestructor){\
			(d)->type->keyDestructor((d)->privdata,(entry)->key);\
		}

#define dictSetKey(d,entry,_key_) do {\
	if((d)->type->keyDup){\
		entry->key = (d)->type->keyDup((d)->privdata,_key_);\
	}else{\
		entry->key = (_key_);\
	}\
}while(0)

#define dictCompareKeys(d,key1,key2)\
		(((d)->type->keyCompare) ? \
			(d)->type->keyCompare((d)->privdata,key1,key2) : \
			(key1) == (key2))

#define dictHashKey(d,key) (d)->type->hashFunction(key)
#define dictGetKey(he) ((he)->key)
#define dictGetVal(he) ((he)->v.val)
#define dictGetSignedIntegerVal(he) ((he)->v.s64)
#define dictGetUnsignedIntegerVal(he) ((he)->v.u64)
#define dictSlots(d) ((d)->ht[0].size+(d)->ht[1].size)
#define dictSize(d) ((d)->ht[0].used+(d)->ht[1].used)
#define dictIsRehashing(ht) ((ht)->reashidx != -1)

dict *dictCreate(dictType *type,void *privDataPtr);
int dictExpand(dict *d,unsigned long size);

int dictAdd(dict *d,void *key,void *val);
dictEntry *dictAddRaw(dict *d,void *key);
int dictReplace(dict *d,void *key,void *val);
dictEntry *dictReplaceRaw(dict *d,void *key);
int dictDelete(dict *d,const void *key);
int dictDeleteNoFree(dict *d,const void *key);
void dictRelease(dict *d);
dictEntry *dictFind(dict *d,const void *key);
void *dictFetchValue(dict *d,const void *key);
int dictResize(dict *d);
dictIterator *dictGetIterator(dict *d);
dictIterator *dictGetSafeIterator(dict *d);
dictEntry *dictNext(dictIterator *iter);
void dictReleaseIterator(dictIterator *iter);
dictEntry *dictGetRandomKey(dict *d);
void dictPrintStats(dict *d);
unsigned int dictGenHashFunction(const void *key,int len);
unsigned int dictGenCaseHashFunction(const unsigned char *buf,int len);
void dictEmpty(dict *d);
void dictEnableResize(void);
void dictDisableResize(void);
int dictRehash(dict *d,int n);
int dictRehashMilliseconds(dict *sd,int ms);
void dictSetHashFunctionSeed(unsigned int initval);
unsigned int dictGetHashFunctionSeed(void);


extern dictType dictTypeHeapStringCopyKey;
extern dictType dictTypeHeapStrings;
extern dictType dictTypeHeapStringCopyKesyValue;




#endif /* DICT_H_ */
