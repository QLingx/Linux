#ifndef ANET_DEFINE_H
#define ANET_DEFINE_H

#define zmalloc malloc
#define zfree(p) if(p){free(p);}
#define zrealloc realloc


#define DEFAULT_BUFF_SIZE 1024

#define DEFAULT_LISTEN_BACKLOG 10240
#define DEFAULT_MAX_CLIENT_COUNT 100000
#define DEFAULT_LISTEN_PORT 12345

#endif