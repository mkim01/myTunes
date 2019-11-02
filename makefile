# all: main.o linkedlist.o
# 	gcc -o program main.o linkedlist.o
#
# main.o: main.c header.h
# 	gcc -c main.c header.h
#
# linkedlist.o: linkedlist.c
# 	gcc -c linkedlist.c
#
# run:
# 	./program
#
# clean:
# 	rm *.o
# 	rm *~

all: main.o linkedList.o
	gcc -o program main.o linkedList.o

main.o: main.c header.h
	gcc -c main.c header.h

linkedList.o: linkedList.c
	gcc -c linkedList.c

run:
	./program

clean:
	rm *.o
	rm *~
