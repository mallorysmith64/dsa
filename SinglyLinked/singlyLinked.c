#include <stdio.h>
#include <stdlib.h>

// In C, we can represent a node using structures
struct Node
{
    int data;
    struct Node *next;
};

// create linked list
int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // dynamically allocate the nodes in the heap
    // Data is random because we haven’t assigned anything yet
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // assign data to first node
    head->data = 1;
    // link first node to second
    head->next = second;

    // assign data to second
    second->data = 2;
    // link second node to third
    second->next = third;

    // assign data to third
    third->data = 3;
    // to terminate the list, last node points to null
    third->next = NULL;

    return 0;
}