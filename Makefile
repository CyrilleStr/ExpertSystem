CFLAGS=-W -Wall
EXEC=main

all: $(EXEC)

main: regle.o main.o 
	gcc -o main regle.o main.o
regle.o: regle.c
	gcc -o regle.o -c regle.c $(CFLAGS)
main.o: main.c regle.h
	gcc -o main.o -c main.c $(CFLAGS)

clean:
	del *.o *.exe