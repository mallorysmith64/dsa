#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// In C, we can represent a node using structures
struct node
{
    int data;
    struct node *next;
} *head = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct node *t, *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayList(struct node *p)
{
    while (p != NULL)
    {
        printf("-> %d", p->data);
        p = p->next;
    }
}

// merge two linked lists
void merge(struct node *p, struct node *q)
{
    struct node *last;

    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;

    if (q)
        last->next = q;
}

void reverseList(struct node *n)
{
    // call function recursively and then print data until n is null or 0
    if (n != NULL)
    {
        reverseList(n->next);
        printf("\n Reversed List:  %d", n->data);
    }
}

// find middle node
struct node *middleNode(struct node *head)
{
    struct node *fast = head, *slow = head; // two pointers: fast and slow

    while (fast != NULL && fast->next != NULL) // check fast and fast next
    {
        fast = fast->next->next; // move fast one more than slow
        slow = slow->next;
    }
    printf("Middle node is: %d \n", slow->data);
    return slow;
}

// check if linked list has a loop or is linear
int isLoop(struct node *f)
{
    struct node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    {
        if (p == q)
            return 1; // yes, there is a loop
        else
            return 0; // no, the the linked list is linear
    }
}

// create linked list
int main()
{
    struct node *t1, *t2;

    int A[] = {2, 2, 2, 4, 8, 10};
    // int B[] = {15, 18, 7, 30, 55, 7};
    create(A, 6);

    t1 = head->next->next;                   // 2
    t2 = head->next->next->next->next->next; // last node
    t2->next = t1;                           // last node should point to t1's node for there to be a loop

    printf("%d \n", isLoop(head));

    // create2(B, 6);

    // merge linked list below:
    // merge(head, second);
    // displayList(third);

    // middleNode(head);
    // displayList(head);

    // reverseList(head);

    return 0;
}