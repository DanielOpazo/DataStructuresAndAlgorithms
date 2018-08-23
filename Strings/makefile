OBJS = main.o strings.o test.o
CC = gcc
CFLAGS = -Wall -c -std=c99
LFLAGS = -Wall

out: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o out

main.o: main.c strings.h test.h
		$(CC) $(CFLAGS) main.c

strings.o: strings.c strings.h
		$(CC) $(CFLAGS) strings.c

test.o: test.c strings.h test.h
		$(CC) $(CFLAGS) test.c

clean:
	\rm *.o out
