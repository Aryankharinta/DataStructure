/* C program that uses functions to perform the following:
a.	Create a binary search tree of integers.
b.	Traverse the above Binary search tree non recursively in order
c.	Calculate its height . */

#include <stdio.h>
  struct node
    {
        int data;
        struct node *left;
        struct node *right;
    }*root=NULL;
struct stnode
{
	struct node *data;
	struct stnode *link;
}*top=NULL;

void insert(int n)
{
 struct node *t=root;
 struct node *q,*r;
 if(root==NULL)
 {
     q=(struct node *)malloc(sizeof(struct node));
     q->data=n;
     q->left=q->right=NULL ;
     root=q;
     return;
 }
 while(t!=NULL)
 {
     r=t;
     if(n<t->data)
        t=t->left;
   else  if(n>t->data)
        t=t->right ;
     else
        return ;
 }
 q=(struct node *)malloc(sizeof(struct node));
     q->data=n;
     q->left=q->right=NULL ;
     if(n<r->data)
        r->left=q;
     else
        r->right=q;
}
void push(struct node *p)
{
	struct stnode *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=p;
	t->link=top;
	top=t;
}

struct node *pop()
{
	struct stnode *t=top;
	struct node *p=top->data;
	top=top->link;
	free(t);
	return p;
}

int isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

void iterativeInorder(struct node *p)
{
	while(p!=NULL||!isempty())
	{
		if(p!=NULL)
		{
			push(p);
			p=p->left;
		}
		else
		{
			p=pop();
			printf("%d ",p->data);
			p=p->right;
		}
	}
}

int heightOfTree(struct node *t)
{
    int p,r;
    if(t==NULL)
     return 0;
     if(!t->left && !t->right)
        return 0;
    else
    {
     p=heightOfTree(t->left);
     r=heightOfTree(t->right);
    return (1+(p>r?p:r));
    }
}
int main()
{
    int m,n,numb;
printf("Enter the no of elements that you want to insert in binary search tree \n");
scanf("%d",&n);
printf("NOTE-First element that you enter will act as Root node\n");
printf("Enter the integer datas to insert in binary  search tree \n");
for (int i = 0; i < n;i++)
	{
		scanf("%d",&numb);
		insert(numb);
	}
printf("Binary search tree of integer input are created \n");
printf("Inorder transversal of tree are: \n ");
iterativeInorder(root);
m=heightOfTree(root);
printf("\nHeight of tree roted at top are %d",m);
return 0;
}