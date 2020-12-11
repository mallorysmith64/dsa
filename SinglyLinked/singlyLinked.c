#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// In C, we can represent a node using structures
struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayList(struct Node *p)
{
    // use while loop b/c we do not know how many nodes they are
    // print the data, then move to next node, then print the data, move to next node
    // condition: stop when n points to NULL or 0
    printf("\n\n [head] <->");
    while (p != NULL)
    {
        printf("%d <->", p->data);
        p = p->next;
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
    int A[] = {2, 2, 2, 4, 8, 10};
    int B[] = {15, 18, 7, 30, 55};
    create(A, 6);
    create2(B, 6);

    displayList(head);
    displayList(second);

    reverseList(head);

    return 0;
}