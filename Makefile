CFLAGS=-W  -I lib/
EXEC=main

all: $(EXEC)

main: build/regle.o build/bc.o build/bf.o build/moteur_inference.o build/interface.o build/main.o
	gcc -o main build/regle.o build/bc.o build/bf.o build/moteur_inference.o build/interface.o build/main.o
build/regle.o: src/regle.c
	gcc -o build/regle.o -c src/regle.c $(CFLAGS)
build/bc.o: src/bc.c
	gcc -o build/bc.o -c src/bc.c $(CFLAGS)
build/bf.o: src/bf.c
	gcc -o build/bf.o -c src/bf.c $(CFLAGS)
build/moteur_inference.o: src/moteur_inference.c
	gcc -o build/moteur_inference.o -c src/moteur_inference.c $(CFLAGS)
build/interface.o: src/interface.c
	gcc -o build/interface.o -c src/interface.c $(CFLAGS)
build/main.o: src/main.c lib/regle.h lib/bc.h lib/bf.h lib/moteur_inference.h lib/interface.h
	gcc -o build/main.o -c src/main.c $(CFLAGS)

clean:
	del *.exe build\*.o
	
