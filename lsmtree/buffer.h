#ifndef _BUF_H
#define _BUF_H

typedef struct buffer_t{
    char *buf;
    int NUL;
    int buflen;
}buffer;

buffer *buffer_new(size_t reserve);
void buffer_free(buffer *b);
void buffer_clear(buffer *b);
char *buffer_detach(buffer *b);

void buffer_putc(buffer *b,const char c);
void buffer_putstr(buffer *b,const char *str);
void buffer_putnstr(buffer *b,const char *str,size_t n);
void buffer_putint(buffer *b,int i);

void buffer_dump(buffer *b);

#endif