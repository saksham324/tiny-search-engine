# Variables
L = ../libcs50
M = ../common

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I $M -I $L
PROG = crawler
OBJS = crawler.o
LLIBS = $L/libcs50-given.a $M/common.a

# Rules
all: $(PROG)

$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(CFLAGS) $^ -o $@

# Phony Targets
.PHONY: clean test

test:
	bash -v testing.sh

clean:
	rm -f core *core.*
	rm -f $(PROG) *~ *.o

valgrind:
	valgrind ./crawler http://cs50tse.cs.dartmouth.edu/tse/ output/letters-depth-1 1