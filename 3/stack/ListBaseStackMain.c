#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include "ListBaseStack.h"

int main(void)
{
	int menu;
    int data;
    int insert, delete;
	Stack s,s2;
	StackInit(&s);
	StackInit(&s2);

    while(menu != 3)
    {
		int x, y;
        printf("[Select menu]\n1.Insert\n2.Delete\n3.return\n-------------\nselect menu : ");
        scanf("%d", &menu);
        if(menu == 1)
        {
            printf("Insert : ");
            scanf("%d", &insert);
            SPush(&s, insert);
        }
        else if(menu == 2)
			SPop(&s);
        else
		{
			system("cls");
			system(".\\sim.exe");
			return 0;
		}
        system("cls");
        printf("\n\n");

		printf("stack data\n");
		while(!SIsEmpty(&s))
		{
			x = SPop(&s);
			SPush(&s2, x);
			printf("%d,", x);
		}
		printf("\n");

		while(!SIsEmpty(&s2))
		{
			SPush(&s, SPop(&s2));
		}
    }
	return 0;
}