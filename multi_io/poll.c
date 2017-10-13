#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<unistd.h>
#include<sys/poll.h>


int main(){

	struct pollfd fds[1];
	int r;
	char buf[127];

	fds[0].fd = 0;
	fds[0].events = POLLIN;

	while(1){
		r = poll(fds,1,-1);
		if(fds[0].revents & POLLIN){
			printf("data income\n");
			r = read(0,buf,126);
		}
	}
	return 0;
}
