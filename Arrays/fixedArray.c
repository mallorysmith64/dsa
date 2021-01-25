#include <stdio.h>
#include <stdlib.h> // needed for malloc

int main()
{
    int *p; // need one pointer to access heap
    int i;

    printf("Fixed Sized Array: \n");

    int A[5] = {2, 4, 6, 8, 10}; // create a fixed sized array

    for (i = 0; i < 5; i++) // iterate through the array
    {
        printf("%d ", A[i]); // print the array's values
    }

    return 0;
}