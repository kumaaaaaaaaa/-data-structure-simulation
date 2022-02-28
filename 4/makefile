pq.out : PriorityQueue.o PriorityQueueSimul.o UsefulHeap.o
	gcc -o pq.out PriorityQueue.o PriorityQueueSimul.o UsefulHeap.o

PriorityQueue.o : PriorityQueue.c
	gcc -c -o PriorityQueue.o PriorityQueue.c

PriorityQueueSimul.o : PriorityQueueSimul.c
	gcc -c -o PriorityQueueSimul.o PriorityQueueSimul.c

UsefulHeap.o : UsefulHeap.c
	gcc -c -o UsefulHeap.o UsefulHeap.c

clean : 
	rm *.o