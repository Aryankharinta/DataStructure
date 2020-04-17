#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*left;
    struct node*right;
}Node;

Node *make()
{
    Node*temp;
    int x;
    printf("enter data otherwise enter -1 for no data\n");
    scanf("%d",&x);
    if(x==-1)
    {printf("you have entered no data\n");
        return NULL;
    }
    temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    printf("enter left\n");
    temp->left=make();

    printf("enter rigt\n");
    temp->right=make();
    return temp;

}
void preorder(Node*t)
{if(!t==NULL){
    printf("%d\n",t->data);
    preorder(t->left);
    preorder(t->right);
}
}
void postorder(Node*t)
{if(!t==NULL){
    postorder(t->left);
    postorder(t->right);
    printf("%d\n",t->data);

}
}
void inorder(Node*t)
{if(!t==NULL){
    preorder(t->left);
    printf("%d\n",t->data);
    preorder(t->right);
}
}
int main()
{
    Node*root;
    root=make();
    printf("root is%d\n",root->data);
    printf("the preorder is\n");
    preorder(root);
    printf("the postorder is\n");
    postorder(root);
    printf("the inorder is\n");
    inorder(root);
}
