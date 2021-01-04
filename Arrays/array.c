#include <stdio.h>
#include <stdlib.h> // needed for malloc

int main()
{
    int A[5] = {1, 2, 3, 4, 5}; // create array
    int *p; // need pointer to access heap
    int i;

    p = (int *)malloc(5 * sizeof(int));

    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;


    printf("Array Indices: ");

    for (i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nPointer Indices: "); // pointer index is like linked list's pointer's data

    for (i = 0; i < 5; i++)
    {
        printf("%d ", p[i]); // pointer index will return all the array values
    }
}