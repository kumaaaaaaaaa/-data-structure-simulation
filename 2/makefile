DLinked.out : DLinked.o DLinkedMain.o
	gcc -o DLinked.out DLinked.o DLinkedMain.o

DLinked.o : DLinked.c
	gcc -c -o DLinked.o DLinked.c

DLinkedMain.o : DLinkedMain.c
	gcc -c -o DLinkedMain.o DLinkedMain.c

clean : 
	rm *.o