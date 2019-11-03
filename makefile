

all: main.o linkedList.o
	gcc -o program main.o linkedList.o

main.o: main.c linkedlist.h
	gcc -c main.c linkedlist.h

linkedList.o: linkedList.c
	gcc -c linkedList.c

run:
	./program

clean:
	rm *.o
	rm *~
