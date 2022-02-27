#include <stdio.h>
#include <process.h>

int main(){
    int menu;
    printf("1. linkded list\n2. queue\n3. stack\n");
    printf("4. Priority queue\n5. search\n6. avl tree\n");
    printf("7. binary tree\n8. table\n9. exit\n");
    printf("Select Menu : ");
    scanf("%d", &menu);
    if(menu == 1)
    {
        system(".\\2\\DLinked.exe");
        return 0;
    }
    else if(menu == 2)
    {
        system(".\\3\\q\\q.exe");
        return 0;
    }
    else if(menu == 3)
    {
        system(".\\3\\stack\\stack.exe");
        return 0;
    }
    else if(menu == 4)
    {
        system(".\\4\\pq.exe");
        return 0;
    }
    else if(menu == 5)
    {
        system(".\\5\\search.exe");
        return 0;
    }
    else if(menu == 6)
    {
        system(".\\6\\avl\\avl.exe");
        return 0;
    }
    else if(menu == 7)
    {
        system(".\\6\\binary\\binary.exe");
        return 0;
    }
    else if(menu == 8)
    {
        system(".\\7\\table.exe");
        return 0;
    }
    else
        return 0;

}