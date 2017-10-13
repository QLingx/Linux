.PHONY:clean

CC=g++
RM=rm
EXE=simple
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

$(EXE):$(OBJS)
	$(CC) -o $@ $^
%.o:%.c
	$(CC) -c $^ -o $@
clean:
	$(RM) $(EXE) $(OBJS)
	

all:first second third
	@echo "\$$@=$@"
	@echo "$$^=$^"
	@echo "$$<=$<"
first second third: