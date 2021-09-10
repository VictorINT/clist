bin: objs/list.o objs/example.o
	gcc objs/list.o objs/example.o -o bin
objs/list.o: src/list.c
	gcc -c src/list.c -o objs/list.o
objs/example.o: example.c
	gcc -c example.c -o objs/example.o

run:
	./bin
