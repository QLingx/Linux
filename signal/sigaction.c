#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void ouch(int sig){
	printf("OUCH! - I got signal %d\n",sig);
}

void s_v1(){
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT,&act,0);

	while(1){
	}
}

void handler(int s){
	printf("handle sigint signal\n");
}

void s_v2(){
	int sum = 0;

	signal(SIGINT,handler);
	sigset_t sigs,sigp,sigq;

	sigemptyset(&sigs);
	sigemptyset(&sigp);
	sigemptyset(&sigq);

	sigaddset(&sigs,SIGINT);

	sigprocmask(SIG_BLOCK,&sigs,0);
	for(int i = 0;i <= 10;i++){
		sum += i;
		printf("test1\n");
		sigpending(&sigp);
		printf("test2\n");
		if(sigismember(&sigp,SIGINT)){
				printf("sigint in queuing\n");
				sigsuspend(&sigq);
//				sigsuspend(&sigp);//block
		}
		sleep(1);
	}
	printf("sum=%d\n",sum);
	sigprocmask(SIG_UNBLOCK,&sigs,0);
	printf("over!\n");
}

int main(){
	s_v2();
	return 0;
}
