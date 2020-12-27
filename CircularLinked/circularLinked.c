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

// length of linked list
int Length(struct node *p)
{
    int len = 0;

    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;

    if (index < 0 || index > Length(head)) // check indices are valid
        return;

    if (index == 0) // check if index is 0
    {
        t = (struct node *)malloc(sizeof(struct node)); // create new node
        t->data = x;                                    // assign data to new node

        if (head == NULL) // check if head is NULL
        {
            head = t;          // if null, make head the new node
            head->next = head; // there is only one node, make head point on itself
        }
        else
        {
            while (p->next != head) // transverse circular list
                p = p->next;
            p->next = t;    // when p is on the last node, p's next should point to new node
            t->next = head; // new node's next should point to head
            head = t;       // head is now the new node inserted
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++) // start at index 0 and insert node index - 1 times
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node)); // create new node to be inserted
        t->data = x;                                    // assign data to new node
        t->next = p->next;
        p->next = t; // p's next should point to new node
    }
}

int main()
{
    int A[] = {2, 2, 2, 4, 8};
    create(A, 5);

    insert(head, 2, 10); // insert at node, index, value

    Rdisplay(head);

    return 0;
}

// Display(head);
// printf("\n");