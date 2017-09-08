#include<stdio.h>
#include<unistd.h>

int main(){
	printf("main:%d\n",getpid());
	int r = execlp("ls","ls","-l",NULL);
	printf("result:%d\n",r);
	return 0;
}
