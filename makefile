all: main

main: main.c
	gcc -W -Wall -o main main.c

clean:
	rm -rf main
