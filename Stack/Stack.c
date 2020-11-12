#include <stdio.h>

int MAX_SIZE = 8;
int stack[8];
// when top = -1, stack is empty
// top is same as size in the js file
int top = -1;

// return element at the top of stack without modifying
int peek()
{
    return stack[top];
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
    printf("Top of Stack is: %d\n", peek());

    push(3);
    push(6);
    push(9);
    push(11);

    pop(9);

    return 0;
}