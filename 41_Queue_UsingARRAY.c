#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int queue[MAX], f = -1, r = -1, item;
void insertion()
{
    if (r == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter the item you want to insert\n");
        scanf("%d", &item);
        if (f == -1)
        {
            f = 0;
        }
        r = r + 1;
        queue[r] = item;
    }
}
void deletion()
{
    if (f == -1 || f > r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = queue[f];
        f = f+1;
        printf("Deleted item is %d\n", item);
    }
}
void display()
{
    if (f == -1 || f > r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The queue is : \n");
        for (int i = f; i <= r; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
int main()
{
    int ch;
    char c;
    while (1)
    {
        printf("press 1.Insertion, 2.Deletion, 3.display, 4.Exit\n");
        printf("Enter your choise\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
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