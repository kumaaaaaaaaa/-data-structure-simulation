q.out : ListBaseQueue.o ListBaseQueuemain.o
	gcc -o q.out ListBaseQueue.o ListBaseQueuemain.o

ListBaseQueuemain.o : ListBaseQueuemain.c
	gcc -c -o ListBaseQueuemain.o ListBaseQueuemain.c

ListBaseQueue.o : ListBaseQueue.c
	gcc -c -o ListBaseQueue.o ListBaseQueue.c

clean : 
	rm *.o