// THE FULL CODE IS NOT RIGHT DEQUEUE RARE PART IS WORKING WRONG NEED TO REVIEW :
#include <stdio.h>
#include <stdlib.h>
 
struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
void enqueueR(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
void enqueueF(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL)
        printf("Queue is Full");
    else{
        n->data = val;
        if(f==NULL){
            f=r=n;
        }
        else{
            n->next = f;
            f=n;
        }
    }
    
}
int dequeueF()
{
    int val = -1;
    struct Node * ptr = f;
    if (f==NULL)
        printf("Queue is empty\n");
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int dequeueR()
{
   int val = -1;
    struct Node * ptr = r;
    struct Node * temp = f;
    // temp->data = -1;
    if (f==NULL)
        printf("Queue is empty\n");
    else
    {
        val = ptr->data;
        while (temp->next == r)
        {
            temp = temp->next;
        }
        // temp = r;
        temp->next = NULL;
        free(ptr);
    }
    return val; 
}
int main()
{
    // printf("Dequeuing element %d\n", dequeue());
    enqueueR(33);
    enqueueR(44);
    enqueueF(22);
    enqueueF(11);
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeueF());
    printf("Dequeuing element %d\n", dequeueR());
    // printf("Dequeuing element %d\n", dequeueR());
    // enqueueF(11);
    // printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}
