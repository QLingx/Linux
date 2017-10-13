#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>


int bssvar;


int main1(){
	char *pmem;
	long heap_gap_bss;

	printf("end of bss session: %p\n",(long)&bssvar + 4);

	pmem = (char*)malloc(32);
	if (pmem == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	printf("pmem: %p\n",pmem);

	heap_gap_bss = (long)pmem - (long)&bssvar - 4;
	printf("1-gap between heap and bss:%lu\n",heap_gap_bss);

	free(pmem);

	sbrk(32);
	pmem = (char*)malloc(32);
	if(pmem == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	printf("pmem: %p\n",pmem);
	heap_gap_bss = (long)pmem - (long)&bssvar - 4;
	printf("2-gap between heap and bss: %lu\n",heap_gap_bss);
	free(pmem);
	return 0;
}

int main2(){
	void *tret;
	char *pmem;

	pmem = (char*)malloc(32);
	if(pmem == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	printf("pmem:%p\n",pmem);

	tret = sbrk(0);
	if(tret != (void*)-1){
		printf("heap size on each load: %lu\n",(long)tret - (long)pmem);
	}
}

int main(){
	void *tret;
	char *pmem;
	int i;
	long sbrkret;

	pmem = (char*)malloc(32);
	if(pmem == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	printf("pmem:%p\n",pmem);

	for(i = 0;i < 65;i++){
		sbrk(1);
		printf("%d\n",sbrk(0) - long(pmem) - 0x20ff0);
	}
	free(pmem);
	return 0;
}
