#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<errno.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<sys/file.h>

void set_nonblock(int fd)
{
    int flag = fcntl(fd,F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd,F_SETFL,flag);
}

int main(){
    int fd = open("/dev/input/mice",O_RDONLY);

    char buf[8];
    while(1){
        int ret = read(fd,buf,sizeof(buf));
        if(ret<0){
            if(errno == EAGAIN){
                printf("EAGAIN\n");
            }else{
                printf("%s\n",buf);
            }
        }
    }

    return 0;
}