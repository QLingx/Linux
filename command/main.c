#include<stdio.h>
#include<string.h>

int main(){
    char str[12] = "hello world";
    char *key = strtok(str," ");
    char *word = strtok(NULL," ");
    printf("%s,%s\n",key,word);
    return 0;
}