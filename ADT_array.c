#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void creatArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void set(struct myArray*a){
    for (int i = 0; i < a->used_size; i++)  
    {
        int n;
        printf("Enter the values %d\n",i+1);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
    
}

void show(struct myArray*a){
    for (int i = 0; i < a->used_size; i++)  
    {
        printf("%d\n",(a->ptr)[i]);
    }
    
}

int main()
{
    struct myArray marks;
    creatArray(&marks, 10 , 5);

    printf("Enter here\n");
    set(&marks);

    printf("You entered\n");
    show(&marks);
    return 0;
}