stack.out : ListBaseStack.o ListBaseStack.o
	gcc -o q.out ListBaseStack.o ListBaseStack.o

ListBaseStackmain.o : ListBaseStackmain.c
	gcc -c -o ListBaseStackmain.o ListBaseStack.c

ListBaseStack.o : ListBaseStack.c
	gcc -c -o ListBaseStack.o ListBaseStack.c

clean : 
	rm *.o