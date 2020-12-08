#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// In C, we can represent a node using structures
struct Node
{
    int data;
    struct Node *next;
};

void displayList(struct Node *n)
{
    // use while loop b/c we do not know how many nodes they are
    // print the data, then move to next node, then print the data, move to next node
    // condition: stop when n points to NULL or 0
    while (n != NULL)
    {
        printf("\n Display List:  %d", n->data);
        n = n->next;
    }
}

void reverseList(struct Node *n)
{
    // call function recursively and then print data until n is null or 0
    if (n != NULL)
    {
        reverseList(n->next);
        printf("\n Reversed List:  %d", n->data);
    }
}

// create linked list
int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // dynamically allocate the nodes in the heap
    // Data is random because we haven’t assigned anything yet
    // if you printf variables, you will get values of 0
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // assign data to first node
    head->data = 100;
    // link first node to second
    head->next = second;

    // assign data to second
    second->data = 25;
    // link second node to third
    second->next = third;

    // assign data to third
    third->data = 30;
    // to terminate the list, last node points to null
    third->next = NULL;

    displayList(head);
    reverseList(head);

    return 0;
}