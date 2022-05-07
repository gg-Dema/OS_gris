CC=gcc
CCOPTS=--std=gnu99 -Wall -D_LIST_DEBUG_
AR=ar

OBJS=LinkedList.o 

HEADERS=LinkedList.h

LIBS=LibLinkedList.a

BINS=LinkedList_test

#disastros_test

.phony: clean all


all:	$(BINS) $(LIBS)


LinkedList.o:	LinkedList.c $(HEADERS)
	$(CC) $(CCOPTS) -c -o $@  $<

LibLinkedList.a:	$(OBJS) 
	$(AR) -rcs $@ $^


LinkedList_test:	LinkedList_test.c $(LIBS)
	$(CC) $(CCOPTS) -o $@ $^

clean:
	rm -rf *.o *~ $(LIBS) $(BINS)
