#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }  
}
struct Node * deleteAtFirst(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node * deleteAtindex(struct Node * head, int index)
{
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node * deleteAtlast(struct Node * head)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct Node * deleteAtgivenval(struct Node * head, int value)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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
    third->next = NULL;

    traversal(head);

    head = deleteAtFirst(head);
    printf("Deletion of 1st node\n");
    traversal(head);

    head = deleteAtindex(head,2);
    printf("Deletion at index node\n");
    traversal(head);

    head = deleteAtlast(head);
    printf("Deletion at last node\n");
    traversal(head);

    head = deleteAtgivenval(head,29);
    printf("Deletion at given value node\n");
    traversal(head);
    return 0;
}