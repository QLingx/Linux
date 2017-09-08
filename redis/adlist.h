/*
 * adlist.h
 *
 *  Created on: Dec 29, 2016
 *      Author: pengcong
 */

#ifndef ADLIST_H_
#define ADLIST_H_

typedef struct listNode{
	struct listNode *prev;
	struct listNode *next;
	void *value;
} listNode;

typedef struct listIter{
	listNode *next;
	int direction;
} listIter;

typedef struct list{
	listNode *head;
	listNode *tail;
	void *(*dup)(void *ptr);
	void *(*free)(void *ptr);
	int (*match)(void *ptr,void *key);
	unsigned long len;
};

#define listLength(l) ((l)->len)
#define listFirst(l) ((l)->head)
#define listLast(l) ((l)->tail)
#define listPrevNode(n) ((n)->prev)
#define listNextNOde(n) ((n)->next)
#define listNodeValue(n) ((n)->value)

#define listSetDupMethod(l,m) ((l)->dup = (m))
#define listSetFreeMethod(l,m) ((l)->free = (m))
#define listSetMatch(l,m) ((l)->match = (m))

list *listCreate(void);
void listRelease(list *list);
list *listAddNodeHead(list *list,void *value);
list *listAddNodeTail(list *list,void *value);
list *listInsertNode(list *list,listNode *old_node,void *value,int after);
void listDelNode(list *list,listNode *node);
listIter *listGetIterator(list *list,int direction);
listNode *listNext(listIter *iter);
void listReleaseIterator(listIter *iter);
list *listDup(list *orig);
listNode *listSearchKey(list *list,void *key);
listNode *listIndex(list *list,long index);
void listRewind(list *list,listIter *li);
void listRewindTail(list *list,listIter *li);
void listRotate(list *list);

#define AL_START_HEAD 0
#define AL_START_TAIL 1


#endif /* ADLIST_H_ */
