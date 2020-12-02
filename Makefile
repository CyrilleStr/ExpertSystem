CFLAGS=-W -Wall -Werror -std=c99 -I lib/
EXEC=main

all: $(EXEC)

main: build/regle.o build/bc.o build/moteur_inference.o build/main.o 
	gcc -o main build/regle.o build/bc.o build/moteur_inference.o build/main.o
build/regle.o: src/regle.c
	gcc -o build/regle.o -c src/regle.c $(CFLAGS)
build/bc.o: src/bc.c
	gcc -o build/bc.o -c src/bc.c $(CFLAGS)
build/moteur_inference.o: src/moteur_inference.c
	gcc -o build/moteur_inference.o -c src/moteur_inference.c $(CFLAGS)
build/main.o: src/main.c lib/regle.h lib/bc.h lib/moteur_inference.h
	gcc -o build/main.o -c src/main.c $(CFLAGS)

clean:
	del *.exe
