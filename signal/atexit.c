#include<stdio.h>
#include<stdlib.h>

void func(){
	printf("over\n");
}

int main(){
	atexit(func);
	printf("main\n");
	return 0;
}
