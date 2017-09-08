#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	int r;
	printf("%d\n",getpid());
	r= system("ls -l");
	printf("%d\n",WEXITSTATUS(r));
	system("clear");
	return 0;
}
