#include "server.h"

void init_server(server_t *server){
    server->loop = aeCreateEventLoop(server->max_client_count);

    server->listen_fd = anetTcpServer();
    if(server->listen_fd != ANET_ERR){
        anetNonBlock(server->err_info,server->listen_fd);
    }

    if(aeCreateFileEvent(server->loop,server->listen_fd,AE_READABLE,acceptTcpHandler,server) != AE_ERR){
        char conn_info[64];
        anetFormatSock(server->listen_fd,conn_info,sizeof(conn_info));
        printf("listen on: %s\n",conn_info);
    }
}

void wait_server(server_t *server){
    aeMain(server->loop);
    aeDeleteEventLoop(server->loop);
}

int main(){
    server_t server;
    bzero(&server,sizeof(server));

    server.backlog = 1024;
    server.max_client_count = 1024;
    server.port = 12345;

    init_server(&server);
    wait_server(&server);    
}