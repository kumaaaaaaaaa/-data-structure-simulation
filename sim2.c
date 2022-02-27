#include <stdio.h>
#include <process.h>
#include <windows.h>

int main(){
    int menu;
    printf("-------------------------------------\n");
    printf("Data Structure Simulator\n");
    printf("-------------------------------------\n");
    printf("1. linkded list\n2. queue\n3. stack\n");
    printf("4. Priority queue\n5. search\n6. avl tree\n");
    printf("7. binary tree\n8. table\n9. exit\n");
    printf("-------------------------------------\n");
    printf("Select Menu : ");
    scanf("%d", &menu);
    if(menu == 1)
    {
        system("cls");
        system(".\\DLinked.exe");
        return 0;
    }
    else if(menu == 2)
    {
        system("cls");
        system(".\\q.exe");
        return 0;
    }
    else if(menu == 3)
    {
        system("cls");
        system(".\\stack.exe");
        return 0;
    }
    else if(menu == 4)
    {
        system("cls");
        system(".\\pq.exe");
        return 0;
    }
    else if(menu == 5)
    {
        system("cls");
        system(".\\search.exe");
        return 0;
    }
    else if(menu == 6)
    {
        system("cls");
        system(".\\avl.exe");
        return 0;
    }
    else if(menu == 7)
    {
        system("cls");
        system(".\\binary.exe");
        return 0;
    }
    else if(menu == 8)
    {
        system("cls");
        system(".\\table.exe");
        return 0;
    }
    else
        return 0;

}