#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // self referential pointer
} * head;              // there is no NULL in circular lists

// create linked list
void create(int A[], int n)
{
    int i;
    struct node *t, *last; // last points to head instead of null
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0]; // head should contain data of first element of an array
    head->next = head; // head next should point on head
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];       // t's data is each array index
        t->next = last->next; // new node's next is last next b/c there is no null
        last->next = t;
        last = t;
    }
}

// print out circular linked list
void Display(struct node *p)
{
    do
    {
        printf("%d -> ", p->data); // print and move to next node
        p = p->next;
    } while (p != head);
}

// print out circular list recursively
void Rdisplay(struct node *p)
{
    static int flag = 0; // indicates if it's the first or second time transversing
    if (p != head || flag == 0)
    { // first time p is equal to head but flag is zero
        flag = 1;
        printf("%d -> ", p->data);
        Rdisplay(p->next);
    }
        flag = 0;
}

int main()
{
    int A[] = {2, 2, 2, 4, 8};
    create(A, 5);

    Display(head);
    
    printf("\n");
    Rdisplay(head);

    return 0;
}