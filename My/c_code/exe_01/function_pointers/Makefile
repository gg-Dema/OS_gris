CC=gcc
AR=ar
CCOPTS=--std=gnu99 -Wall 

BINS=test_function_pointers
OBJS=functions.o
HEADERS=functions.h
LIBS=function_lib.a

.phony: clean all

all:	$(LIBS) $(BINS)

%.o:	%.c $(HEADERS)
	$(CC) $(CCOPTS) -c -o $@ $<
	
$(LIBS):	$(OBJS)
	$(AR) -rcs $@ $^

test_function_pointers:	test_function_pointers.c $(LIBS)
	$(CC) $^ $(CCOPTS) -o $@

clean: 
	rm -rf *.o *.~ $(LIBS) $(BINS)
