SRCS = $(wildcard *[^ll].c)
#SRCS = del.c del_alternate.c middle.c loop.c k_end.c
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS) testll

%: %.c ll.o
	gcc -o $@ $< ll.o

testll: testll.c ll.o
	gcc -o testll testll.c ll.o

ll.o: ll.c ll.h
	gcc -c ll.c

.PHONY: clean
clean:
	rm -f $(PROGS)
