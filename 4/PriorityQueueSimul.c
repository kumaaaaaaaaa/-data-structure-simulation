#include <stdio.h>
#include "PriorityQueue.h"
#include <stdlib.h>
#include <process.h>
#include <windows.h>

int DataPriorityComp(char ch1, char ch2)
{
	return ch2-ch1;
}

int main(){
    int menu;
    PQueue pq;
    int data;
    int insert, delete;
    PQueueInit(&pq, DataPriorityComp);
	

    while(menu != 4)
    {
        printf("[Select menu]\n1.Insert\n2.Delete\n3.Number of data\n4.return\n-------------\nselect menu : ");
        scanf("%d", &menu);
        if(menu == 1)
        {
            printf("Insert : ");
            scanf("%d", &insert);
            PEnqueue(&pq, insert);
			system("cls");
        }
        else if(menu == 2)
        {
           PDequeue(&pq);
		   system("cls");
        }
        else if(menu == 3)
        {
			system("cls");
            printf("numOfData %d \n", pq.numOfData);
        }
        else
		{
            system("cls");
			system(".\\sim.exe");
			return 0;
		}

		for(int i=1; i<=pq.numOfData; i++)
		{
			printf("%d ",pq.heapArr[i]);
		}
		
        
        printf("\n\n");
    }
}

