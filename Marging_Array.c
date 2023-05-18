#include <stdio.h>
int main()
{
    int a1[20], a2[20], a3[30], i, j, k, n, m, d, e, f;
    printf("Enter the length of the 1st array\n");
    scanf("%d", &m);
    printf("Enter the element of the aray:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &a1[i]);
    printf("Enter the length of the 2nd array\n");
    scanf("%d", &n);
    printf("Enter the element of the aray:\n");
    for (j = 0; j < n; j++)
        scanf("%d", &a2[j]);
    i = 0, j = 0, k = 0;
    while ((i < m) && (j < n))
    {
        if (a1[i] <= a2[j])
        {
            a3[k] = a1[i++];
            k++;
        }
        else
        {
            a3[k] = a2[j++];
            k++;
        }
    }
    while (i < m)
    {
        a3[k] = a1[i++];
        k++;
    }
    while (j < n)
    {
        a3[k] = a2[j++];
        k++;
    }
    printf("Merged array arr3 is\n");
    for (i = 0; i < m + n; i++)
        printf("%d ", a3[i]);
    printf("\n");
    return 0;
}
