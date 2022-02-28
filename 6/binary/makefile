binary.out : BinarySearchTree2.o binary.o BinaryTree3.o
	gcc -o binary.out AVLRebalance.o BinarySearchTree3.o BinaryTree3.o

BinarySearchTree2.o : BinarySearchTree2.c
	gcc -c -o BinarySearchTree2.o BinarySearchTree2.c

binary.o : binary.c
	gcc -c -o binary.o binary.c

BinaryTree3.o : BinaryTree3.c
	gcc -c -o BinaryTree3.o BinaryTree3.c

clean : 
	rm *.o