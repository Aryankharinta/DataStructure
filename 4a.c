#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
int deque[max];
int front, back;

int rem(int a, int b)
{
    int r = a % b;
    return r >= 0 ? r : r + b;
}

void pushBack(int temp)
{
    deque[back] = temp;
    back++;
    back = rem(back, max);
}

void popBack()
{
    if(front != back)
    {
        printf("Popping %d", deque[back]);
        back--;
        back = rem(back, max);
    }
    else
    {
        printf("Already Empty.");
    }
    
}

void pushFront(int temp)
{
    deque[front] = temp;
    front--;
    front = rem(front, max);
}

void popFront()
{
    if(back != front)
    {
        printf("Popping %d", deque[front]);
        front++;
        front = rem(front, max);
    }
    else
    {
        printf("Already Empty.");
    }
    
}

void printList()
{
    printf("\nThe List Is: ");
    for(int i = front; i != back; i = rem(i+1, max))
        printf("%d ", deque[i]);
    printf("\n\n");
}

int main()
{
    front = 0; back = 1;
    char choice; int temp;
    while(choice != 'Q' || choice != 'q')
    {
        printf("What do you want to do?\n");
        printf("\t A - Insert Node At End\n");
        printf("\t B - Insert Node in Beginning\n");
        printf("\t C - Delete Node From End\n");
        printf("\t D - Delete Node From Beginning\n");
        printf("\t E - Display List\n");
        printf("\t Z - Clear Screen\n");
        printf("\tQ - Quit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);
        choice = toupper(choice);
        if(choice == 'A')
        {
            printf("Enter Value To Insert At End: ");
            scanf("%d", &temp);
            pushBack(temp);
        }
        else if(choice == 'B')
        {
            printf("Enter Value To Insert At Beginning: ");
            scanf("%d", &temp);
            pushFront(temp);
        }
        else if(choice == 'C')
            popBack();
        else if(choice == 'D')
            popFront();
        else if(choice == 'E')
        {
            printList();
        }
        else if(choice == 'Z')
        {
            system("cls");
        }
        else
        {
            printf("Invalid choice.");
        }
    }
}