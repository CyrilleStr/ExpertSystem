CFLAGS=-W -Wall -Werror -std=c99 -I lib/
EXEC=main

all: $(EXEC)

main: build/regle.o build/bc.o build/bf.o build/moteur_inference.o build/main.o
	gcc -o main build/regle.o build/bc.o build/bf.o build/moteur_inference.o build/main.o
jeu1: build/regle.o build/bc.o build/bf.o build/moteur_inference.o build/jeu1.o
	gcc -o jeu1 build/regle.o build/bc.o build/bf.o build/moteur_inference.o build/jeu1.o

build/regle.o: src/regle.c
	gcc -o build/regle.o -c src/regle.c $(CFLAGS)
build/bc.o: src/bc.c
	gcc -o build/bc.o -c src/bc.c $(CFLAGS)
build/bf.o: src/bf.c
	gcc -o build/bf.o -c src/bf.c $(CFLAGS)
build/moteur_inference.o: src/moteur_inference.c
	gcc -o build/moteur_inference.o -c src/moteur_inference.c $(CFLAGS)
build/main.o: src/main.c lib/regle.h lib/bc.h lib/bf.h lib/moteur_inference.h
	gcc -o build/main.o -c src/main.c $(CFLAGS)
build/jeu1.o: src/jeu1.c lib/regle.h lib/bc.h lib/bf.h lib/moteur_inference.h
	gcc -o build/jeu1.o -c src/jeu1.c $(CFLAGS)

clean:
	del build\*.o
	del *.exe
