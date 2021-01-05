CFLAGS=-W -Wall -std=c99 -g -I lib/

all: jeu1 jeu2 jeu3

jeu1: build/regle.o build/bc.o build/interface.o build/moteur_inference.o build/jeu1.o
	gcc -o jeu1 build/regle.o build/bc.o build/interface.o build/moteur_inference.o build/jeu1.o
jeu2: build/regle.o build/bc.o  build/moteur_inference.o build/interface.o build/jeu2.o
	gcc -o jeu2 build/regle.o build/bc.o  build/moteur_inference.o build/interface.o build/jeu2.o
jeu3: build/regle.o build/bc.o build/moteur_inference.o build/interface.o build/jeu3.o
	gcc -o jeu3 build/regle.o build/bc.o build/moteur_inference.o build/interface.o build/jeu3.o

build/regle.o: src/regle.c
	gcc -o build/regle.o -c src/regle.c $(CFLAGS)
build/bc.o: src/bc.c
	gcc -o build/bc.o -c src/bc.c $(CFLAGS)
build/moteur_inference.o: src/moteur_inference.c
	gcc -o build/moteur_inference.o -c src/moteur_inference.c $(CFLAGS)
build/interface.o: src/interface.c
	gcc -o build/interface.o -c src/interface.c $(CFLAGS)
build/jeu1.o: src/jeu1.c lib/regle.h lib/bc.h  lib/moteur_inference.h
	gcc -o build/jeu1.o -c src/jeu1.c $(CFLAGS)
build/jeu2.o: src/jeu2.c lib/regle.h lib/bc.h  lib/moteur_inference.h
	gcc -o build/jeu2.o -c src/jeu2.c $(CFLAGS)
build/jeu3.o: src/jeu3.c lib/regle.h lib/bc.h lib/moteur_inference.h
	gcc -o build/jeu3.o -c src/jeu3.c $(CFLAGS)

clean:
	del build\*.o
	del *.exe
