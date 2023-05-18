#include <stdio.h>
int linersearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("Element %d found at index %d\n", element, i + 1);
            return i;
        }
    }
    printf("Element not found\n");
    return -1;
}
int binarysearch(int arr[], int size, int element)
{
    int low, high, mid, f = 0;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            f += 1;
            break;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (f == 1)
    {
        printf("Element %d found \n", element);
    }
    else
    {
        printf("Element %d not found \n", element);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 45, 76, 96};
    int size = 13, element;
    printf("Enter the element you want to search\n");
    scanf("%d", &element);
    // linersearch(arr, size, element);
    binarysearch(arr, size, element);
    return 0;
}