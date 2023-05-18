#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        printf("Pooped element is : %d\n", x);
        return x;
    }
}
int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        printf("Peek element is : %d\n", ptr->data);
        return ptr->data;
    }
}
int stackTop()
{
    printf("Top element is : %d\n", top->data);
    return top->data;
}
int bottom(struct Node *t)
{
    struct Node *k = t;
    while (k->next != NULL)
    {
        k = k->next;
    }
    printf("Bottom element: %d\n", k->data);
    return k->data;
}

int main()
{
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 19);
    top = push(top, 89);
    top = push(top, 8);

    linkedListTraversal(top);

    pop(top);
    linkedListTraversal(top);
    peek(1);
    for (int i = 1; i <= 5; i++)
    {
        printf("At pos %d is \n", i);
        peek(i);
    }
    stackTop();
    bottom(top);
    return 0;
}
