#include <stdio.h>
#include <stdlib.h>

// doubly linked list has 2 pointers: next and prev
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;


int count()
{
    struct node *p = head;
    if (p != 0)
    {
        printf("\n Number of nodes: %d", p->data);
        return count(p->next) + 1;
    }
    else
    {
        printf("\n There are 0 nodes. %d", p->data);
        return 0;
    }
}