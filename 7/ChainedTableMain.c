#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;
	int menu, ssn;
	char name[10], addr[10];

	TBLInit(&myTbl, MyHashFunc);

	while(menu != 4)
	{
		printf("1. insert data\n2. delete data\n3. search data\n4. return\n");
		scanf("%d", &menu);
		if(menu == 1)
		{
			printf("insert data. ex) 000123 kim seoul\n");
			scanf("%d %s %s", &ssn, &name, &addr);
			np = MakePersonData(ssn, name, addr);
			TBLInsert(&myTbl, GetSSN(np), np);
			system("cls");
		}

		else if(menu == 2)
		{
			printf("delete data. input ssn\n");
			scanf("%d", &ssn);
			rp = TBLDelete(&myTbl, ssn);
			if(rp != NULL)
				free(rp);
			system("cls");
		}
		else if(menu == 3)
		{
			printf("search data. input ssn\n");
			scanf("%d", &ssn);
			sp = TBLSearch(&myTbl, ssn);
			system("cls");
			if(sp != NULL)
				ShowPerInfo(sp);
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