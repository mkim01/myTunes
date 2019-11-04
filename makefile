

all: main.o linkedlist.o library.o
	gcc -o program main.o linkedlist.o library.o

main.o: main.c linkedlist.h library.h
	gcc -c main.c linkedlist.h library.h

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c linkedlist.h

library.o: library.c library.h linkedlist.h
	gcc -c library.c library.h linkedlist.h

run:
	./program

clean:
	rm *.o
	rm *~


memcheck:
	valgrind --leak-check=yes ./program
