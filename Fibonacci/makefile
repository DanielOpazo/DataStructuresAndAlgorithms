OBJS = main.o fibonacci.o 
CC = gcc
CFLAGS = -Wall -c -std=c99
LFLAGS = -Wall

out: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o out

main.o: main.c fibonacci.h
		$(CC) $(CFLAGS) main.c

fibonacci.o: fibonacci.c fibonacci.h
		$(CC) $(CFLAGS) fibonacci.c

clean:
	\rm *.o out
