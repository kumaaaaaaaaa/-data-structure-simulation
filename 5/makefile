search.out : ListBaseQueue.o UsefulHeap.o search.o
	gcc -o search.out ListBaseQueue.o UsefulHeap.o search.o

ListBaseQueue.o : ListBaseQueue.c
	gcc -c -o ListBaseQueue.o ListBaseQueue.c

UsefulHeap.o : UsefulHeap.c
	gcc -c -o UsefulHeap.o UsefulHeap.c

search.o : search.c
	gcc -c -o search.o search.c

clean : 
	rm *.o