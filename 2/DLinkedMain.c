#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include "DLinked.h"

int main(){
    int menu;
    List list; // LinkedList
    int data;
    int insert, delete;
    ListInit(&list);

    while(menu != 4)
    {
        printf("[Select menu]\n1.Insert\n2.Delete\n3.Number of data\n4.return\n-------------\nselect menu : ");
        scanf("%d", &menu);
        if(menu == 1)
        {
            printf("Insert : ");
            scanf("%d", &insert);
            LInsert(&list, insert);
        }
        else if(menu == 2)
        {
            printf("Delete : ");
            scanf("%d", &delete);
            if(LFirst(&list, &data))
            {
                if(data == delete)
                    LRemove(&list);
                
                while(LNext(&list, &data))
                {
                    if(data == delete)
                        LRemove(&list);
                }
            }
        }
        else if(menu == 3)
        {
            printf("Num of Data : %d\n", LCount(&list));
        }
        else
		{
            system("cls");
			system(".\\sim.exe");
			return 0;
		}
        system("cls");
        if(LFirst(&list, &data))
        {
            printf("Linked List\n");
            printf("%d ", data);

            while(LNext(&list, &data))
            printf("%d ", data);
        }
        printf("\n\n");
    }
}