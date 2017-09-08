#include<stdio.h>
#include<signal.h>
#include<sys/time.h>

void deal(int s){
	printf("time on\n");
}

int main(){
	struct itimerval v = {0};
	signal(SIGALRM,deal);
	v.it_value.tv_sec = 0;
	v.it_value.tv_usec = 1;
	v.it_interval.tv_sec = 1;

	setitimer(ITIMER_REAL,&v,0);
	while(1){

	}
	return 0;
}
