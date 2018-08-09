OBJS = main.o LinkedList.o tests.o
CC = gcc
CFLAGS = -Wall -c
LFLAGS = -Wall

out: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o out

main.o: main.c tests.h
		$(CC) $(CFLAGS) main.c

LinkedList.o: LinkedList.c LinkedList.h
		$(CC) $(CFLAGS) LinkedList.c

tests.o: tests.c tests.h LinkedList.h
		$(CC) $(CFLAGS) tests.c

clean:
	\rm *.o out
