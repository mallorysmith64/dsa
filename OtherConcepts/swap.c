#include <stdio.h>

// swap
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int num = 3; int num2 = 2;
    printf("Original numbers: %d and %d\n", num, num2); //before swap

    swap(&num, &num2);
    printf("Swapped numbers: %d and %d \n", num, num2); //after swap

    return 0;
}