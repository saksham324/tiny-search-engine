# Variables
L = ../libcs50
M = ../common

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I $M -I $L
PROG1 = indexer
PROG2 = indextest
OBJS1 = indexer.o
OBJS2 = indextest.o
LLIBS = $L/libcs50-given.a $M/common.a

# Rules
all: $(PROG1) $(PROG2)

$(PROG1): $(OBJS1) $(LLIBS)
	$(CC) $(CFLAGS) $(OBJS1) -o $(PROG1)

$(PROG2): $(OBJS2) $(LLIBS)
	$(CC) $(CFLAGS) $(OBJS2) -o $(PROG2)

# Phony Targets
.PHONY: clean test

test:
	bash -v testing.sh

clean:
	rm -f core *core.*
	rm -f $(PROG1) $(PROG2) *~ *.o

valgrind:
	valgrind ./indexer
	valgrind ./indextest 