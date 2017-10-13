#include<sys/epoll.h>

typedef struct aeApiState{
	int epfd;
	struct epoll_event *events
}aeApiState;

static int aeApiCreate(aeEventLoop *eventLoop){

}

static void aeApiFree(aeEventLoop *eventLoop){

}


static int aeApiAddEvent(aeEventLoop *eventLoop,int fd,int mask){

}

static void aeApiDelEvent(aeEventLoop *eventLoop,int fd,int delmask){

}

static int aeApiPoll(aeEventLoop *eventLoop,struct timeval *tvp){

}

static char *aeApiName(void){

}

