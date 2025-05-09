CC=clang
CFLAGS=-O3 -Wall

weeks: weeks.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	rm *.o