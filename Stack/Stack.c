#include <stdio.h>

int MAX_SIZE = 8;
int stack[8];
// when top = -1, stack is empty
int top = -1;

// cannot add if stack is full
// not full then push element
int push(int data)
{
    // top < size - 1 makes sure stack isn't full
    if (top < MAX_SIZE - 1)
    {
        top++;
        stack[top] = data;
        printf("added element: %d \n", data);
    }

    else
    {
        printf("Stack Overflow!!! \n");
    }

    return data;
}

// cannot remove if empty
// not empty then pop element
int pop(int data)
{

    if (top >= 0)
        stack[top] = data;
    top--;
    printf("removed element: %d \n", data);
    return data;
}

int peek(int data)
{
    printf("peek element: %d \n", data);
    return stack[top];
}

int main()
{
    push(3);
    pop(9);
}