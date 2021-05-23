#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array createArr)
{
    int i;
    printf("Elements are: \n");
    for (i = 0; i < createArr.length; i++)
        printf("%d ", createArr.A[i]);
}

int main()
{
    struct Array createArr;
    int n, i;

    printf("Enter size for array: \n");
    scanf("%d", &createArr.size);
    createArr.A = (int *)malloc(createArr.size * sizeof(int));
    createArr.length = 0;

    printf("Enter number of numbers: ");
    scanf("%d", &n);

    printf("Enter all Elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &createArr.A[i]);
        createArr.length = n;
    }

    Display(createArr);

    return 0;
}