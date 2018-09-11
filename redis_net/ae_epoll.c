#include<sys/epoll.h>
#include "ae.h"


typedef struct aeApiState{
    int epfd;
    struct epoll_event *events;
}aeApiState;

int aeApiCreate(aeEventLoop *eventLoop){
     aeApiState *state = zmalloc(sizeof(aeApiState));

     if(!state){
         goto err;
     }
     state->events = zmalloc(sizeof(struct epoll_event) * eventLoop->setsize);
     if(!state->events){
         goto err;
     }

     state->epfd = epoll_create(1024);
     if(state->epfd == -1){
         goto err;
     }
     eventLoop->apidata = state;

     return 0;

     err:
     if(state){
         zfree(state->events);
         zfree(state);
     }

     return -1;
}

int aeApiResize(aeEventLoop *eventLoop,int setsize){
    aeApiState *state = eventLoop->apidata;

    state->events = zrealloc(state->events,sizeof(struct epoll_event) * setsize);
    return 0;
}

void aeApiFree(aeEventLoop *eventLoop){
    aeApiState *state = eventLoop->apidata;

    close(state->epfd);
    zfree(state->events);
    zfree(state);
}

int aeApiAddEvent(aeEventLoop *eventLoop,int fd,int mask){
    aeApiState *state = eventLoop->apidata;
    struct epoll_event ee = {0};

    int op = eventLoop->events[fd].mask == AE_NONE ? EPOLL_CTL_ADD : EPOLL_CTL_MOD;

    ee.events = 0;
    mask |= eventLoop->events[fd].mask;
    if(mask & AE_READABLE){
        ee.events |= EPOLLIN;
    }
    if(mask & AE_WRITEABLE){
        ee.events |= EPOLLOUT;
    }

    ee.data.fd = fd;
    if(epoll_ctl(state->epfd,op,fd,&ee) == -1){
        return -1;
    }

    return 0;
}