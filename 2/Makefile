
.PHONY: all
all:
	rm -rf build && mkdir build
	gcc -c -Wall queue.c -o build/queue.o
	gcc -c -Wall main.c -o build/main.o
	gcc build/queue.o build/main.o -o build/main
