#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int inddeletion(int arr[], int size, int index)
{
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[20] = {12, 13, 14, 15, 16};
    int size = 5, index = 2;
    display(arr, size);
    inddeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}