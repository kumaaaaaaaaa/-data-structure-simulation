#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include "ListBaseQueue.h"

int main(void)
{
	int menu;
    int data;
    int insert, delete;
	Queue q,q2;
	QueueInit(&q);
	QueueInit(&q2);

    while(1)
    {
		int x, y;
        printf("[Select menu]\n1.Insert\n2.Delete\n3.return\n-------------\nselect menu : ");
        scanf("%d", &menu);
        if(menu == 1)
        {
            printf("Insert : ");
            scanf("%d", &insert);
            Enqueue(&q, insert);
        }
        else if(menu == 2)
			Dequeue(&q);
        else
		{
			system("cls");
			system(".\\sim.exe");
			return 0;
		}
        system("cls");
        printf("\n\n");

		printf("Q data\n");
		while(!QIsEmpty(&q))
		{
			x = Dequeue(&q);
			Enqueue(&q2, x);
			printf("%d,", x);
		}
		printf("\n");

		while(!QIsEmpty(&q2))
		{
			Enqueue(&q, Dequeue(&q2));
		}
    }
	return 0;
}