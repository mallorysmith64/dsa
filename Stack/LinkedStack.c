#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

// write push function
void push(int x)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node)); // create new node

    if (p == NULL)
        // if new node points to null stack is full
        printf("Stack Overflow \n");
    else
    {
        p->data = x;
        p->next = top;
        top = p;
    }
}

int pop()
{
    struct Node *p; // need pointer to delete node
    int x = -1;     // return -1 if stack is empty

    if (top == NULL)
        printf("Stack Underflow \n");
    else
    {
        p = top;         // p should be pointing on top
        top = top->next; // move top
        x = p->data;     // take value of topmost node
        free(p);         // then delete the node
    }
    return x; // return -1 if stack is empty else return 1
}

void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL) // to display transverse through list via while loop
    {
        printf("%d ", p->data); // format values
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(2);
    push(8);

    Display();

    pop(2);

    printf("Removed element(s):%d ", pop());

    return 0;
}