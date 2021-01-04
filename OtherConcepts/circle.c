#include <stdio.h>

void circle(int rows, int cols)
{
    int i, j;

    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= cols; j++)
        {
            // Print corner element
            if ((i == 1 || i == rows) && (j == 1 || j == cols))
            {
                printf("0");
            }
            else if (i == 1 || i == rows || j == 1 || j == cols)
            {
                // Print edge
                printf("1");
            }
            else
            {
                // Print center
                printf("0");
            }
        }

        printf("\n");
    }
}

int main()
{

    int rows = 1; // row is vertical asterisks
    int cols = 2; // column is horizontal asterisks
    
    circle(rows, cols);
    printf("\t");

    circle(rows,cols);
    printf("\t");

    circle(rows,cols);
    printf("\t");

    circle(rows,cols);
    printf("\t");

    return 0;
}