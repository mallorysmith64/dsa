#include <stdio.h>
#include <stdlib.h> // needed for malloc

int main()
{
    int *p, *q; // need two pointers for dynamic array
    int i;

    p = (int *)malloc(5 * sizeof(int)); // create array in heap called p
    p[0] = 2; // assign data to p array
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;

    printf("Dynamic Array: \n");

    q = (int *)malloc(10 * sizeof(int)); // create another array called q

    for (i = 0; i < 5; i++)
        q[i] = p[i];
    free(p); // deallocate p memory
    p = q;
    q = NULL;

    for (i = 0; i < 5; i++)
        printf("%d ", p[i]); // pointer index will return all the array values

    return 0;
}