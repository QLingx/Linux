/*
 * ae.h
 *
 *  Created on: Apr 8, 2017
 *      Author: pengcong
 */

#ifndef AE_H_
#define AE_H_

#define AE_OK 0
#define AE_ERR -1

#define AE_NONE 0
#define AE_READABLE 1
#define AE_WRITEABLE 2

#define AE_FILE_EVENTS 1
#define AE_TIME_EVENTS 2
#define AE_ALL_EVENTS (AE_FILE_EVENT|AE_TIME_EVENTS)
#define AE_DONT_WAIT 4

#define AE_NOMORE -1

#define AE_NOTUSED(V) ((void) V)

struct aeEventLoop;

typedef void aeFileProc(struct aeEventLoop *eventloop,int fd,void *clientdata,int mask);
typedef int aeTimeProc(struct aeEventLoop *eventloop,long long id,void *clientdata);
typedef void aeEventFinalizerProc(struct aeEventLoop *eventloop,void *clientdata);
typedef void aeBeforeSleepProc(struct aeEventLoop *eventloop);

typedef struct aeFileEvent{
	int mask;
	aeFileProc *rfileProc;
	aeFileProc *wfileProc;
	void *clientData;
}aeFileEvent;

typedef struct aeTimeEvent{
	long long id;
	long when_sec;
	long when_ms;
	aeTimeProc *timeProc;
	aeEventFinalizerProc *finalizerProc;
	void *clientData;
	struct aeTimeEvent *next;
}aeTimeEvent;

typedef struct aeFiredEvent{
	int fd;
	int mask;
}aeFiredEvent;

typedef struct aeEventLoop{
	int maxfd;
	int setsize;
	long long timeEventNextId;
	time_t lastTime;
	aeFileEvent *events;
	aeFiredEvent *fired;
	aeTimeEvent *timeEventHead;
	int stop;
	void *apidata;
	aeBeforeSleepProc *beforesleep;
}aeEventLoop;

aeEventLoop *aeCreateEventLoop(int setsize);
void aeDeleteEventLoop(aeEventLoop *eventloop);
void aeStop(aeEventLoop *eventLoop);
int aeCreateFileEvent(aeEventLoop *eventLoop,int fd,int mask);
int aeGetFileEvents(aeEventLoop *eventLoop,int fd);
long long aeCreateTimeEvent(aeEventLoop *eventLoop,
		long long milliseconds,
		aeTimeProc *proc,
		void *clientdata,
		aeEventFinalizerProc *finalizerProc);
int aeDeleteTimeEvent(aeEventLoop *eventLoop,long long id);
int aeProcessEvents(aeEventLoop *eventLoop,int flags);
int aeWait(int fd,int mask,long long milliseconds);
void aeMain(aeEventLoop *eventLoop);
char *aeGetApiName(void);
void aeSetBeforeSleepProc(aeEventLoop *eventLoop,aeBeforeSleepProc *beforesleep);


#endif /* AE_H_ */
