#include<stdio.h>
#include<stdlib.h>
//Node structure
struct node
{
    int data;
    struct node *next;
};
struct node *head=0,*temp,*newnode;
//creating a node using function
void createnode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    printf("enter the data : ");
    scanf("%d",&newnode->data);
    if(head==0)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=temp->next;
    }
}
//deletion of node
void deletenode(int x)
{
    struct node *prev;
    temp=head;
    while(temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}
//display elements of linked list
void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
   int n,x;
   printf("enter no. of nodes : ");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       createnode();
   }
   printf("enter the integer to be deleted : ");
   scanf("%d",&x);
   deletenode(x);
   display();
   return 0;
}