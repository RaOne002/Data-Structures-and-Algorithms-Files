#include <stdio.h>
void seletionSort(int *a, int n)
{
    int min,temp;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[min])
            {
                min = j;
            }   
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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
    seletionSort(a,n);
    printf("Your array is\n");
    for (int j = 0; j < n; j++)
        printf("%d ", a[j]);
} 

/*
    Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
     00  01  02  03  04
    |03, 05, 02, 13, 12

    After first pass
     00  01  02  03  04
     02,|05, 03, 13, 12

    After second pass
    00  01  02  03  04
    02, 03,|05, 13, 12

    After third pass
    00  01  02  03  04
    02, 03, 05,|13, 12

    After fourth pass
    00  01  02  03  04
    02, 03, 05, 12,|13
*/