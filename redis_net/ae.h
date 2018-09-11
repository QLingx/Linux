#ifndef ANET_AE_H
#define ANET_AE_H

#include<time.h>

#define AE_OK 0
#define AE_ERR -1

#define AE_NONE 0
#define AE_READABLE 1
#define AE_WRITEABLE 2

#define AE_FILE_EVENTS 1
#define AE_TIME_EVENTS 2
#define AE_ALL_EVENTS (AE_FILE_EVENTS | AE_TIME_EVENTS)
#define AE_DONT_WAIT 4

#define AE_NOMORE -1
#define AE_DELETE_EVENT_ID -1

#define AE_NOTUSED(V) ((void)V)

struct aeEventLoop;

typedef void aeFileProc(struct aeEventLoop *eventLoop,int fd,void *clientdata,int mask);
typedef int aeTimeProc(struct aeEventLoop *eventLoop,long long fd,void *clientdata);
typedef void aeEventFinalizerProc(struct aeEventLoop *eventLoop,void *clientdata);
typedef void aeBeforeSleepProc(struct aeEventLoop *eventLoop);

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

aeEventLoop* aeCreateEventLoop(int setsize);

#endif