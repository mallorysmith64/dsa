#include <stdio.h>

int MAX_SIZE = 8;
int stack[8];
// when top = -1, stack is empty
// top is same as size in the js file
int top = -1;

// peek means to check value of specific index
int peek()
{
    if (top == -1)
    {
        printf("Stack is Empty! \n");
        return -1;
    }
    else
        return (stack[top]);
}

// cannot add if stack is full
// not full then push element
int push(int element)
{
    // top < size - 1 makes sure stack isn't full
    if (top < MAX_SIZE - 1)
    {
        top++;
        stack[top] = element;
        printf("added element: %d \n", element);
    }

    else
    {
        printf("Stack Overflow!!! \n");
    }
}

// cannot remove if empty
// not empty then pop element
int pop(int element)
{

    if (top >= 0)
    {
        stack[top] = element;
        top--;
        printf("removed element: %d \n", element);
    }
    else
        printf("Stack is empty!!!");
}

// test stack by performing operations
int main()
{

    push(3);
    push(6);
    push(9);
    push(11);

    pop(11);

    printf("\nTop of Stack is: %d\n", peek()); // call peek after adding/removing elements

    return 0;
}