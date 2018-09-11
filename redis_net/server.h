#ifndef ANET_SERVER_H
#define ANET_SERVER_H

#include "ae.h"

typedef struct{
    aeEventLoop *loop;
    int listen_fd;
    int port;
    int backlog;
    int max_client_count;
    char err_info[1024];
}server_t;

typedef struct{
    aeEventLoop *loop;
    int fd;
    buffer_t *read_buffer;
    buffer_t *write_buffer;
}client_t;

void init_server(server_t *server);
void wait_server(server_t *server);
#endif