#include <stdio.h>

/* Generic Circle Equation: ( x - h )^2 + ( y - k )^2 = r^2, 
// where ( h, k ) is the center and r is the radius

// Circle at Origin: x^2 + y^2 = r^2,
// where h = 0 and k = 0
*/

int circle_eq(int x, int y, int radius)
{
    return (x * x) + (y * y) - radius; // circle at origin equation
}

void draw_circle(int radius)
{
    int x, y;
    for (x = -2; x <= 2; x++) // space below and above circle
    {
        for (y = -4; y <= 4; y++) // move circle left or right
        {
            if (circle_eq(x, y, radius) < 0)
                printf("**"); // 1 asterisk = half circle
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main()
{
    int x = 4, y = 4, radius = 8; // coordinates, radius, size of circle
    printf("Coordinates: (%d, %d)\nRadius is: %d\n", x, y, radius);

    int size = (x * x) + (y * y) - radius; // calculate size of circle
    printf("Size is: %d\n\n", size);

    draw_circle(radius); // draw circle with asterisks

    return 0;
}