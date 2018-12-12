#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<errno.h>
#include<sys/mman.h>
#include<sys/types.h>

void sighandle(int v){
    printf("SIGPIPE\n");
}

int main(){
    int fd[2];
    int ret = pipe(fd);
#if 0
    signal(SIGPIPE,sighandle);
    close(fd[0]);

    ret = write(fd[1],"buf",3);
    if(ret < 0){
        perror("write");
        printf("ERRNO: %d\n",errno);
    }
#endif

#if 0
    char buf[1];
    for(int i = 0;;i++){
        write(fd[1],buf,1);
        printf("%d\n",i);
    }
#endif

    pid_t pid = fork();
    if(pid == 0){
        sleep(1);
        close(fd[0]);
        write(fd[1],"hello",5);
    }else{
        close(fd[1]);
        char buf[10] = {0};
        read(fd[0],buf,sizeof(buf));
        printf("%s\n",buf);
    }
    return 0;
}