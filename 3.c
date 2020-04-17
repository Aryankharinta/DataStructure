#include<stdio.h>
//implementing stack using arrays
char u[30],s[30];
int t=-1;
void push(char y)
{
    t++;
    s[t]=y;
}
void pop()
{
    printf("%c",s[t]);
    t--;
}
void checkplus(char x)
{
     if(s[t]=='*'||s[t]=='/'||s[t]=='+'||s[t]=='-'||s[t]=='^')
     {
         while(s[t]=='*'||s[t]=='/'||s[t]=='+'||s[t]=='-'||s[t]=='^')
         {
             pop();
         }
         push(x);
     }
     else
     {
         push(x);
     }
}
void checkmultiply(char y)
{
    if(s[t]=='*'||s[t]=='/'||s[t]=='^')
    {
       while(s[t]=='*'||s[t]=='/'||s[t]=='^')
         {
             pop();
         }
         push(y);
    }
    else
    {
        push(y);
    }
}
void checkbkt(char z)
{
    while(s[t]!='(')
    {
        pop();
    }
    t--;
}
void main()
{
    printf("enter the infix expression : ");
    gets(u);
    int j=0;
    while(u[j])
    {
        if(u[j]=='+'||u[j]=='-')
        {
            checkplus(u[j]);
        }
        else if(u[j]=='*'||u[j]=='/')
        {
            checkmultiply(u[j]);
        }
        else if(u[j]=='^')
        {
            push(u[j]);
        }
        else if(u[j]=='(')
        {
            push(u[j]);
        }
        else if(u[j]==')')
        {
            checkbkt(u[j]);
        }
        else
        {
          printf("%c",u[j]);
        }
        j++;
    }
    while(t!=-1)
    {
        pop();
    }
}
