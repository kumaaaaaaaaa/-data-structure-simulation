#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include "BinarySearchTree2.h"

int main(){
    int menu, insert, delete;
    BTreeNode * bstRoot;
	BTreeNode * sNode;    // search node

    BSTMakeAndInit(&bstRoot);

    
    while(1)
    {
        printf("menu\n1. insert\n2. Delete\n3. return\n");
        scanf("%d", &menu);
        if(menu == 1)
        {
            printf("Insert : ");
            scanf("%d", &insert);
            BSTInsert(&bstRoot, insert);
        }

        else if(menu == 2)
        {
            printf("Delete : ");
            scanf("%d", &delete);
            sNode = BSTRemove(&bstRoot, delete);
            free(sNode);
        }
        else
		{
            system("cls");
			system(".\\sim.exe");
			return 0;
		}
        system("cls");
        printf("binary tree\n");
        BSTShowAll(bstRoot);
        printf("\n");
    }



    return 0;

}