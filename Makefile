CFLAGS=-O0 -Wall

cacheid: cacheid.o
	gcc -o $@ $^

clean:
	rm -f *.o cacheid
