#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int cqueue[MAX], f = -1, r = -1, item;
void insertion()
{
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter the item\n");
        scanf("%d", &item);
        if (f == -1)
        {
            f = 0;
            r = 0;
        }
        else
        {
            if (r == MAX - 1)
            {
                r = 0;
            }
            else
                r = r + 1;
        }
        cqueue[r] = item;
    }
}
void deletion()
{
    if (f == -1)
        printf("Queue is empty\n");
    else
    {
        item = cqueue[f];
        printf("Deleted item is %d\n", item);
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        if (f == MAX - 1)
        {
            f = 0;
        }
        else
            f++;
    }
}
void display()
{
    if (f == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Circular queue is :     \n");
        if (f <= r)
        {
            for (int i = 0; i <= f - 1; i++)
                printf("_,");
            for (int i = f; i <= r; i++)
                printf("%d", cqueue[i]);
            for (int i = r + 1; i <= f - 1; i++)
                printf("_,");
            for (int i = f; i <= MAX - 1; i++)
                printf("%d", cqueue[i]);
        }
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\nPress 1.Insert,2.Delete,3.Display,4.Exit\n");
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
            printf("Wrong choice !\n");
            break;
        }
    }
    return 0;
}