#include <stdio.h>
void bubbleSort(int *a, int n)
{
    int temp;
    int isSort = 0;
    for (int i = 0; i < n - 1; i++)
    {
        isSort = 1;
        // printf("step needed %d\n",i+1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSort = 0;
            }
        }
        if (isSort)
            return;
    }
}
int main()
{
    int m,n, a[20];
    printf("Enter the array length\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubbleSort(a,n);
    printf("Your array is\n");
    for (int j = 0; j < n; j++)
        printf("%d ", a[j]);
}  