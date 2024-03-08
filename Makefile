CC=gcc
CFLAGS=-g -std=c17 -Wall

all: test_tree

clean:
	rm -vf *.o test_tree

redblk_tree.o: redblk_tree.c redblk_tree.h
	$(CC) $(CFLAGS) -DVER=$(VERS) -c $*.c -o $@

test_tree.o: test_tree.c redblk_tree.o
	$(CC) $(CFLAGS) -DVER=$(VERS) -c $*.c -o $@

test_tree: test_tree.o redblk_tree.o
	$(CC) -o $@ $(CFLAGS) $< redblk_tree.o

