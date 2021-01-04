// Draw triangle
#include <stdio.h>

void triangle(int rows)
{
    int i, j;

    for (i = 1; i <= rows; i++) // need two nested for loops to draw rows
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int rows;
    float base = 3;
    float height = 3;

    printf("Base is: %.1f\nHeight is: %.1f\n", base, height); // Give Triangle Dimensions and Area

    float area = 0.5 * (base * height); // find area
    printf("Area is: %.1f\n\n", area);

    triangle(area); // draw triangle

    return 0;
}