CC := gcc
CFLAGS := -w -std=gnu99 -ggdb -ffunction-sections
LFLAGS := lpthread
BINS := redis
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

.PHONY: all clean

all:$(BINS)

BINOS = $(addsuffix .o,$(BINS))
TEMP_OBJ = $(filter-out $(BINOS),$^)

$(BINS):$(OBJS)
	@echo ""
	$(foreach BIN,$@,$(CC) $(CFLAGS) $(TEMP_OBJ) $(BIN).o $(LFLAGS) -o $(BIN));

%.d:%.c
	@echo "";\
	rm -f $@;\
	$(CC) -MM $< > $@.$$$$;\

-include $(SRCS:.c=.d)

clean:
	rm -f *.o *.d
	rm -f $(BINS)