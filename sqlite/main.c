#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct InputBuffer_t{
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
}InputBuffer;

InputBuffer* new_input_buffer(){
    InputBuffer *input_buffer = malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
}

void print_prompt(){
    printf("db > ");
}

void read_input(InputBuffer *input_buffer){
    ssize_t nread = getline(&(input_buffer->buffer),&(input_buffer->buffer_length),stdin);
    if(nread <= 0){
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }
    input_buffer->input_length = nread - 1;
    input_buffer->buffer[nread-1] = '\0';
}

int main(){
    InputBuffer *input_buffer = new_input_buffer();
    while(true){
        print_prompt();
        read_input(input_buffer);

        if(strcmp(input_buffer->buffer,".exit") == 0){
            exit(EXIT_SUCCESS);
        }else{
            printf("Unrecognized command '%s'.\n",input_buffer->buffer);
        }
    }
}