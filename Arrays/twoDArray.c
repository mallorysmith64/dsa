#include <stdio.h>
#include <stdlib.h> // needed for malloc

int main()
{
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}}; // 3 rows and 4 columns
    int *B[3]; // created inside stack
    int **C;
    int i, j;

    for (i = 0; i < 3; i++) // nested for loop used for 2d arrays, iterate through rows
    {
        for (j = 0; j < 4; j++) // iterate through columns
            printf("%d ", A[i][j]);
            printf("\n");
    }

    B[0] = (int *)malloc(4 * sizeof(int)); // create array in heap and assign
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));

    C = (int **)malloc(3 * sizeof(int *));
    C[0] = (int *)malloc(4 * sizeof(int *));
    C[1] = (int *)malloc(4 * sizeof(int *));
    C[2] = (int *)malloc(4 * sizeof(int *));

    return 0;
}
