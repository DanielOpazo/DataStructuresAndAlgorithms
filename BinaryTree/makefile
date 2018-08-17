OBJS = main.o BinaryTree.o test.o
CC = gcc
CFLAGS = -Wall -c -std=c99
LFLAGS = -Wall

out: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o out

main.o: main.c BinaryTree.h test.h
		$(CC) $(CFLAGS) main.c

BinaryTree.o: BinaryTree.c BinaryTree.h
		$(CC) $(CFLAGS) BinaryTree.c

test.o: test.c BinaryTree.h test.h
		$(CC) $(CFLAGS) test.c

clean:
	\rm *.o out
