#include<stdio.h>
#include"ae.h"
#include "ae_epoll.c"

aeEventLoop* aeCreateEventLoop(int setsize){
    aeEventLoop *eventLoop;

    if(eventLoop == zmalloc(sizeof(*eventLoop)) == NULL){
        goto err;
    }

    eventLoop->events = zmalloc(sizeof(aeFileEvent) * setsize);
    eventLoop->fired = zmalloc(sizeof(aeFiredEvent) * setsize);

    if (eventLoop->events == NULL || eventLoop->fired == NULL){
        goto err;
    }

    eventLoop->setsize = setsize;
    eventLoop->lastTime = time(NULL);
    eventLoop->timeEventHead = NULL;
    eventLoop->timeEventNextId = 0;
    eventLoop->stop = 0;
    eventLoop->maxfd = -1;
    eventLoop->beforesleep = NULL;

    if(aeApiCreate(eventLoop) == -1){
        goto err;
    }

    for(int i = 0;i < setsize;i++){
        eventLoop->events[i].mask = AE_NONE;
    }

    return eventLoop;
    err:
    if(eventLoop){
        zfree(eventLoop->events);
        zfree(eventLoop->fired);
        zfree(eventLoop);
    }

    return NULL;

}

int aeGetSetSize(aeEventLoop *eventLoop){
    return eventLoop->setsize;
}

int aeResizeSetSize(aeEventLoop *eventLoop,int setsize){
    if(setsize == eventLoop->setsize){
        return AE_OK;
    }

    if (eventLoop->maxfd >= setsize){
        return AE_ERR;
    }

    if(aeApiResize(eventLoop,setsize) == -1){
        return AE_ERR;
    }

    eventLoop->events = zrealloc(eventLoop->events,sizeof(aeFileEvent) * setsize);
    eventLoop->fired = zrealloc(eventLoop->fired,sizeof(aeFiredEvent)*setsize);
    eventLoop->setsize = setsize;

    for(int i = eventLoop->maxfd+1;i < setsize;i++){
        eventLoop->events[i].mask = AE_NONE;
    }

    return AE_OK;
}