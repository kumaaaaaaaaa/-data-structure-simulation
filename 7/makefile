table.out : ChainedTableMain.o DLinkedList.o Person.o Table2.o
	gcc -o table.out ChainedTableMain.o DLinkedList.o Person.o Table2.o

ChainedTableMain.o : ChainedTableMain.c
	gcc -c -o ChainedTableMain.o ChainedTableMain.c

DLinkedList.o : DLinkedList.c
	gcc -c -o DLinkedList.o DLinkedList.c

Person.o : Person.c
	gcc -c -o Person.o Person.c

Person.o : Table2.c
	gcc -c -o Table2.o Table2.c

clean : 
	rm *.o