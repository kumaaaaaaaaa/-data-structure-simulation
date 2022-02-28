avl.out : AVLRebalance.o BinarySearchTree3.o BinaryTree3.o avl.o
	gcc -o avl.out AVLRebalance.o BinarySearchTree3.o BinaryTree3.o avl.o

AVLRebalance.o : AVLRebalance.c
	gcc -c -o AVLRebalance.o AVLRebalance.c

BinarySearchTree3.o : BinarySearchTree3.c
	gcc -c -o BinarySearchTree3.o BinarySearchTree3.c

BinaryTree3.o : BinaryTree3.c
	gcc -c -o BinaryTree3.o BinaryTree3.c

avl.o : avl.c
	gcc -c -o avl.o avl.c

clean : 
	rm *.o