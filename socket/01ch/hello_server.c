#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void error_handling(const char *message){
    fputs(message,stderr);
    fputc('\n',stderr);
    exit(-1);
}

int main(int argc,char *argv[]){
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[] = "Hello World NICE TO MEET YOU HAHA";

    if(argc != 2){
        printf("Usage : %s <port>\n",argv[0]);
        exit(1);
    }

// create socket
    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == -1){
        error_handling("socket() error");
    }
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

// bind ip and port
    if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
        error_handling("bind() error");
    }

// able to connect
    if(listen(serv_sock,5) == -1){
        error_handling("listen() error");
    }

    clnt_addr_size = sizeof(clnt_addr);
    // accept connection
    clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
    if(clnt_sock == -1){
        error_handling("accept() error");
    }

    printf("message: %s\n",message);
    write(clnt_sock,message,sizeof(message));

    // usleep(10000000);
    close(clnt_sock);
    close(serv_sock);

    printf("\nserver run here\n");
    return 0;
}