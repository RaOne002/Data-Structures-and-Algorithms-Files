#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void push(struct stack *s,int value)
{
    int val;
    if (isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top = s->top+1;
        printf("Enter the value you want to push\n");
        scanf("%d",&val);
        s->arr[s->top] = val;
    } 
}
int pop(struct stack *s)
{
    if (isEmpty(s))
    {
       printf("Stack is empty\n"); 
       return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top = s->top-1;
        printf("Pop element is %d\n",val);
        return val;
    }
}
int main()
{
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->arr[0] = 7;
    s->top++;
    // if (isEmpty(s))
    // {
    //     printf("Stack is empty\n");
    // }
    // else
    //     printf("Stack is not empty\n");

    // if (isFull(s))
    // {
    //     printf("Stack is full\n");
    // }
    // else
    //     printf("Stack is not full\n");
    push(s,12);
    pop(s);
    return 0;
}