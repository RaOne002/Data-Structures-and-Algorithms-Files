#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *start = NULL;
void create(int data)
{
    struct node *temp, *q;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        q = start;
        while (q->link != NULL)
            q = q->link;
        q->link = temp;
    }
}
void insertAtBeg(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    start = temp;
}
void insertAtAny(int pos, int data)
{
    struct node *q, *temp;
    q = start;
    for (int i = 0; i < pos - 1; i++)
    {
        q = q->link;
        if (q == NULL)
            printf("Invalid position\n");
    }
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = q->link;
    q->link = temp;
}
void insertAtEnd(int data)
{
    struct node *temp, *q;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        q = start;
        while (q->link != NULL)
            q = q->link;
        q->link = temp;
    }
}
// THERE IS SOME MISTAKE IN DELETION
void deletion(int data)
{
    struct node *temp, *q;
    if (start->link == NULL)
    {
        if (start->info == data)
        {
            temp = start;
            free(temp);
            start = NULL;
        }
    }
    else if (start->info == data)
    {
        temp = start;
        start = start->link;
        free(temp);

        q = start;
        while (q->link->link != NULL)
        {
            if (q->link->info == data)
            {
                temp = q->link;
                q->link = temp->link;
                free(temp);
            }
            q = q->link;
        }
    }
    else if (q->link->info == data)
    {
        temp = q->link;
        free(temp);
        q->link = NULL;
    }
    printf("Element %d deleted\n", data);
}
void display()
{
    struct node *q;
    if (start == NULL)
        printf("List is empty\n");
    else
    {
        q = start;
        while (q != NULL)
        {
            printf("%d\n", q->info);
            q = q->link;
        }
    }
}
int main()
{
    int ch, a, b, c, d, e, f, g;
    while (1)
    {
        printf("Press 1.Create, 2.Insertn at begning, 3.Insert at end," 
        "4.Insert ar any position, 5.Delete, 6.Display, 7.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the size of the list\n");
            scanf("%d", &a);
            printf("Enter the elements\n");
            for (int i = 0; i < a; i++)
            {
                scanf("%d", &b);
                create(b);
            }
            break;
        case 2:
            printf("Enter the data\n");
            scanf("%d", &c);
            insertAtBeg(c);
            break;

        case 3:
            printf("Enter the data\n");
            scanf("%d", &d);
            insertAtEnd(d);
            break;

        case 4:
            printf("Enter the position\n");
            scanf("%d", &e);
            printf("Enter the data\n");
            scanf("%d", &f);
            insertAtAny(e, f);
            break;

        case 5:
            printf("Enter the element\n");
            scanf("%d", &g);
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Wrong choise\n");
            break;
        }
    }

    return 0;
}