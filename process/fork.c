#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
#include<sys/mman.h>
#include<fcntl.h>

void p_v1(){
	int pid;
	printf("before process created!\n");
	pid = fork();
	if(pid == 0){
		while(1){
			printf("child process\n");
			sleep(1);
		}
	}else{
		while(1){
			printf("father process\n");
			sleep(1);
		}
	}
}

void p_v2_deal(int s){
	int status;
	wait(&status);
	printf("handling...\n");
	sleep(5);
	printf("handle over:%d\n",WEXITSTATUS(status));
}

void p_v2(){
	if(fork() == 0){
		printf("child!\n");
		sleep(20);
		printf("c exit\n");
		exit(88);
	}else{
		signal(17,p_v2_deal);
		sleep(20000);
		printf("parent\n");
	}
}

void p_v3(){
	if(fork()){
		int fd = open("test.txt",O_RDWR);
		printf("%d\n",fd);
		sleep(5);
		write(fd,"killer",6);
		close(fd);
	}else{
		int fd = open("test.txt",O_RDWR);
		printf("%d\n",fd);
		write(fd,"Clinton",7);
		sleep(8);
		close(fd);
	}
}

void p_v4(){
	int *a = mmap(0,4,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,0,0);
//	int *a = sbrk(4);
	*a = 40;
	if(fork()){
		printf("parent:%d\n",*a);
		*a = 90;
	}else{
		printf("child:%d\n",*a);
		sleep(3);
		printf("child:%d\n",*a);
	}
}

int main(){
	p_v4();
	return 0;
}
