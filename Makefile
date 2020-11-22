CFLAGS=-W -Wall
EXEC=main

all: $(EXEC)

main: build/regle.o build/main.o
	gcc -o main build/regle.o build/main.o
build/regle.o: src/regle.c
	gcc -o build/regle.o -c src/regle.c $(CFLAGS)
build/main.o: src/main.c lib/regle.h
	gcc -o build/main.o -c src/main.c $(CFLAGS)

clean:
	del *.exe /build/*.o