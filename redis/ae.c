#include<stdio.h>
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
#include<poll.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<errno.h>

#include "ae.h"
#include "zmalloc.h"
#include "config.h"
#include "ae_evport.c"
#include "ae_epoll.c"
#include "ae_kqueue.c"
#include "ae_select.c"


aeEventLoop *aeCreateEventLoop(int setsize){
	aeEventLoop *eventLoop;
	int i;
}


void aeDeleteEventLoop(aeEventLoop *event){

}

void aeStop(aeEventLoop *eventLoop){

}

int aeCreateFileEvent(aeEventLoop *eventLoop,int fd,int mask,aeFileProc *proc,void *clientData){

}

void aeDeleteFileEvent(aeEventLoop *eventLoop,int fd,int mask){

}

int aeGetFileEvents(aeEventLoop *eventLoop,int fd){

}

static void aeGetTime(long *second,long *milliseconds){

}

static void aeAddMillisecondsToNow(long long milliseconds,long *sec,long *ms){

}

long long aeCreateTimeEvent(aeEventLoop *eventLoop,long long millseconds,aeTimeProc *proc,void *clientData,aeEventFinalizerProc *finalizerProc){

}

int aeDeleteTimeEvent(aeEventLoop *eventLoop,long long id){

}

static aeTimeEvent *aeSearchNearestTimer(aeEventLoop *eventLoop){

}

static int processTimeEvents(aeEventLoop *eventLoop){

}

int aeProcessEvents(aeEventLoop *eventLoop,int flags){

}

int aeWait(int fd,int mask,long long milliseconds){

}

void aeMain(aeEventLoop *eventLoop){

}

char *aeGetApiName(void){

}

void aeSetBeforeSleepProc(aeEventLoop *eventLoop,aeBeforeSleepProc *beforesleep){

}




