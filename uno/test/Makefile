CFLAGS = -Wall -Wextra -g -std=c99
LDLIBS = -lm

all: test

test: test.o
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

test.o: test.c
	$(CC) $(CFLAGS) $(LDLIBS) $^ -c $@

clean: 
	rm -f *.o test