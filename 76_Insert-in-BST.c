#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

void insret(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct node *new = createNode(key);
    if(key < prev->data)
    prev->left = new;
    else
    prev->right = new;
}
int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // printf("Preorder\n");
    // preOrder(p);
    // printf("\nPostorder\n");
    // postOrder(p);
    printf("\nInitially\n");
    inOrder(p);
    printf("\nAfter insert :-\n");
    // printf("%d\n", isBst(p));
    // if (isBST(p))
    // {
    //     printf("This is a BST\n");
    // }
    // else
    //     printf("This is not a BST\n");
    insret(p,7);
    inOrder(p);
    printf("\n");
    if (isBST(p))
    {
        printf("This is a BST\n");
    }
    else
        printf("This is not a BST\n");
    return 0;
}