clist.o: src/clist.c
	gcc -c src/clist.c -o clist.o

clean:
	rm clist.o
