CFLAGS = -Wall -std=c99 -Wextra -g

all: test

test: test.o
	$(CC) $(CFLAGS) $^ -o $@

test.o: test.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o test

.PHONY: all clean