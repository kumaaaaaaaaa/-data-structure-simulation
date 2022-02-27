#include <stdio.h>
#include <windows.h>
#include <process.h>
#include "BinaryTree3.h"	// 트리의 구조를 확인하기 위해서
#include "BinarySearchTree3.h"

int main(void)
{
    BTreeNode * avlRoot;
	BTreeNode * clNode;
	BTreeNode * crNode;	
	BSTMakeAndInit(&avlRoot);

    int insert, menu;


    
    while(1)
    {
        int r = 0,l = 0;
        printf("menu\n1.insert\n2.left node\n3.right node\n4.root node\n5.return\n");
        scanf("%d",&menu);

        if(menu == 1)
        {
            system("cls");
            printf("insert : ");
            scanf("%d", &insert);
            BSTInsert(&avlRoot, insert);
        }
        else if(menu == 2)
        {
            while(l != 2)
            {
                printf("1. countinue 2. exit\n");
                scanf("%d", &l);
                clNode = GetLeftSubTree(avlRoot);
                printf("left node : %d\n", GetData(clNode));
            }

        }
        else if(menu == 3)
        {
            while(r != 2)
            {
                printf("1. countinue 2. exit\n");
                scanf("%d", &r);
                crNode = GetRightSubTree(avlRoot);
                printf("right node : %d\n", GetData(crNode));
            }
            
        }
        else if(menu ==4)
        {
            system("cls");
            printf("root node : %d\n", GetData(avlRoot));
        }
        else
		{
            system("cls");
			system(".\\sim.exe");
			return 0;
		}
    }

    return 0;
    
}