#include <stdio.h>
void insertionSort(int *a, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
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
    insertionSort(a, n);
    printf("Your array is\n");
    for (int j = 0; j < n; j++)
        printf("%d ", a[j]);
}
/* 
    THE WAY OF INSERTION SORT
   -1   0    1   2   3   4   5
        12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
        12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

        12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
        12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

        12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
        12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
        12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
        12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
        07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   Fast forwarding and 4th and 5th pass will give:
        07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
        07, 12, 23, 54,| 65, 09 --> After the 4th pass

        07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
*/
