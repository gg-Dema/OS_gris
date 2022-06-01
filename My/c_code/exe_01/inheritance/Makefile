CC = gcc
CCOPTS = --std=gnu99 -Wall 
AR = ar

BINS = test_float_linked_list
OBJS = linked_list_float.o linked_list.o
LIBS = lib_linked_list.a
HEADERS = float_linked_list.h linked_list.h

.phony: clean all 

all:	$(BINS) $(LIBS)

linked_list.o: linked_list.c $(HEADERS)
	$(CC) $(CCOPTS) -c -o $@ $<
	
linked_list_float.o: float_linked_list.c $(HEADERS)
	$(CC) $(CCOPTS) -c -o $@ $<

lib_linked_list.a: $(OBJS)
	$(AR) -rcs $@ $^

test_float_linked_list: test_float_linked_list.c $(LIBS)
	$(CC) $(CCOPTS) -o $@ $^
