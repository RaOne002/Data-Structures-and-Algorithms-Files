#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++, k++;
        }
        else
        {
            B[k] = A[j];
            j++, k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++, i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++, j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}
int main()
{
    // int i, m,a[20];
    // printf("Enter the size of the 1st array\n");
    // scanf("%d", &m);
    // printf("Enter the elements \n");
    // for (int i = 0; i < m; i++)
    //     scanf("%d", &a[i]);
    // printArray(a, m);
    // mergeSort(a, a[0], a[m]);
    // printArray(a, m);

    int b[] = {1, 23, 2, 45, 67};
    printArray(b, 5);
    mergeSort(b, 0, 5);
    printArray(b, 5);
    return 0;
}
// MARGE 2 ARRAYS ->
/*
#include <stdio.h>
void merge()
{
    int a[20], b[20], b[20], mid, n, k, i, j;
    i = j = k = 0;
    printf("Enter the size of the 1st array\n");
    scanf("%d", &mid);
    printf("Enter the elements \n");
    for (int i = 0; i < mid; i++)
        scanf("%d", &a[i]);

    printf("Enter the size of the 2nd array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int j = 0; j < n; j++)
        scanf("%d", &b[j]);

    while (i < mid && j < n)
    {
        if (a[i] < b[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        b[k] = b[j];
        j++, k++;
    }
    printf("The final array is\n");
    for (int k = 0; k < mid + n; k++)
        printf("%d  ", b[k]);
}
int main()
{
    merge();
    return 0;
}
*/