#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX], top = -1, item;
void push()
{
   if (top == MAX-1)
   printf("The stack is full\n");
   else
   {
    printf("Enter the element\n");
    scanf("%d",&item);
    top = top+1;
    stack[top] = item;
   }    
}
void pop()
{
    if(top == -1)
    printf("The stack is empty\n");
    else
    {
        item = stack[top];
        top = top-1;
        printf("Deleted item is %d",item);
    }
}
void display()
{
   if(top == -1)
    printf("The stack is empty\n");
    else
    {
        printf("The stack is\n");
        for (int i = top; i >= 0 ; i--)
            printf("%d\n",stack[i]); 
    } 
}
int main()
{
    int a[10],ch;
    while (1)
    {
        printf("\nPress 1.Push,2.Pop,3.Dispaly,4.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
        printf("Wrong choise\n");
            break;
        }
    }
    return 0;
}