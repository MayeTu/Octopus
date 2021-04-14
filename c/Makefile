all: store
	gcc main.o list.o item.o function.o util.o -o store

store: list item function 
	gcc main.c -c 

function: list item
	gcc function.c -c

list: item util
	gcc list.c -c

item:
	gcc item.c -c

util:
	gcc util.c -c

clean:
	rm -vf *.o a.out store
