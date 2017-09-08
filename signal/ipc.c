#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main(){
	int fd[2];
	pipe(fd);
	if(fork()){
		close(fd[0]);
		while(1){
			write(fd[1],"hello",5);
			sleep(1);
		}
	}else{
		char buf[20];
		int r;
		close(fd[1]);
		while(1){
			r = read(fd[0],buf,20);
			buf[r] = 0;
			printf("::%s\n",buf);
		}
	}
	return 0;
}
