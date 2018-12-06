prog: main.o game.o
	gcc -std=c99 -o prog main.o game.o
main.o: main.c
	gcc -std=c99 -c main.c
game.o: game.c
	gcc -std=c99 -c game.c

clean:
	rm -f prog main.o game.o
