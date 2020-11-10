// FIFO - linear data structure

#include <stdio.h>
#define MAX 8

int items[MAX], front = -1, rear = -1;

// added to rear
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full!!!");
    }
    else
    {
        rear++;
        items[rear] = value;
        printf("\n Added element: %d", value);
    }
}

// remove from front
void dequeue(int value)
{
    // if empty, cannot remove
    if (front == rear)
    {
        printf("\n Queue is empty!!!");
    }
    else
    {
        front++;
        value = items[front];
        printf("\n Removed element: %d", value);
    }
}

// test queue by performing operations:
int main()
{
    enqueue(4);
    enqueue(6);
    enqueue(8);

    dequeue(4);
    dequeue(6);
    dequeue(8);

    return 0;
}