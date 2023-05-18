#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void triversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct  Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data =data;

    struct Node * p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 82;
    second->next = third;

    third->data = 29;
    third->next = head;

    triversal(head);
    printf("Linked list after insertion\n");
    head = insertAtFirst(head,32);
    triversal(head);
    return 0;
}