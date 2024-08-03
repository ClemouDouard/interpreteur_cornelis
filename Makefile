output: main.o image.o pile.o 
	gcc main.o image.o pile.o -o output

main.o: main.c
	gcc -c main.c

image.o: image.c image.h
	gcc -c image.c

pile.o: pile.c pile.h
	gcc -c pile.c