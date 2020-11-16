#include <stdio.h>
#include <stdlib.h>

// In C, we can represent a node using structures
struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node* n)
{
    while (n != NULL) {
        printf("\n Value of Node:  %d", n-> data);
        n = n-> next;
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

    printList(head);

    return 0;
}