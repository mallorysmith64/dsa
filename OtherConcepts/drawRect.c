#include <stdio.h>

// draw rectangle
void rect(int w, int l)
{
    int i, j;

    for (i = 1; i <= w; i++) // need two nested for loops for width and length
    {
        for (j = 1; j <= l; j++)
        {
            if (i == 1 || i == w || j == 1 || j == w) // if not empty or input print asterisk
                printf("*");
            else
                printf(" "); // else print empty space
        }
        printf("\n"); // don't forget to add a newline
    }
}

int main()
{
    int width = 6; // row is vertical asterisks
    int length = 6; // column is horizontal asterisks
    printf("Length is: %d\nWidth is: %d\n", width, length); // display rectangle dimensions

    // find perimeter
    int perimeter = 2 * length + 2 * width; // perimeter formula is: P = 2l + 2w
    printf("Perimeter is: %d\n", perimeter);

    // find area
    int area = width * length;
    printf("Area is: %d\n\n", area);

    rect(width, length);

    return 0;
}