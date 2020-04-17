/* C program that to calculate: Number of Nodes in a Binary Tree */

#include <stdio.h>
  struct node
            {
                int data;
                struct node *left;
                struct node *right;
            }*root;
struct node *create()
{
 int x;
struct node *newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter the integer data for the nodes(-1 for no data)");
 scanf("%d", &x);
 if(x==-1)
 {
     return NULL;
      }
      newnode->data=x;
      printf("Enter the left child  data rooted at %d \n",newnode->data);
      newnode->left=create();
      printf("Enter the right child data rooted at %d\n",newnode->data);
      newnode->right=create();
      return newnode;
}
int NoOfNode(struct node *t)
{
    if(t)
    {
        return (1+NoOfNode(t->left)+NoOfNode(t->right));
    }
    else
    return 0;
}
int main()
{
 root=create();
 printf("Binary tree are created \n");
struct node *t=root;
int n=NoOfNode(t);
printf("\n No. of node in binary tree are %d",n);
return 0;
}