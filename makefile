

all: main.o linkedList.o library.o
	gcc -o program main.o linkedList.o library.o

main.o: main.c linkedlist.h library.h
	gcc -c main.c linkedlist.h library.h

linkedList.o: linkedList.c linkedlist.h
	gcc -c linkedList.c linkedlist.h

library.o: library.c library.h linkedlist.h
	gcc -c library.c library.h linkedlist.h

run:
	./program

clean:
	rm *.o
	rm *~
