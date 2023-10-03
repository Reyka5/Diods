# Makefile for onoff
onoff: on_off.o main.o
	gcc -o onoff on_off.o main.o
	
on_off.o: on_off.c on_off.h
	gcc -c on_off.c
	
main.o: main.c
	gcc -c main.c
	
clean:
	rm -f *.o
	rm -f onoff
