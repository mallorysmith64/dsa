#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //needed for INT_MIN

// doubly ped list has 2 pointers: next and prev
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL; //global decration of head node
struct node *second = NULL;
struct node *third = NULL;
struct node *tail = NULL;
struct node *current = NULL;

// create first list
void create(int data)
{
    // allocate memory for new node
    struct node *p = (struct node *)malloc(sizeof(struct node));

    p->data = data;
    p->prev = NULL;
    p->next = NULL;

    // if head is empty, create a new list
    if (head == NULL)
    {
        head = p;
        return;
    }

    current = head;

    // move to the end of the list
    while (current->next != NULL)
        current = current->next;

    // insert p at the end of the list
    current->next = p;
    tail = p;
    p->prev = current;
}

// create second list
void create2(int data)
{
    // allocate memory for new node
    struct node *p = (struct node *)malloc(sizeof(struct node));

    p->data = data;
    p->prev = NULL;
    p->next = NULL;

    // if head is empty, create a new list
    if (head == NULL)
    {
        head = p;
        return;
    }

    current = head;

    // move to the end of the list
    while (current->next != NULL)
        current = current->next;

    // insert p at the end of the list
    current->next = p;
    tail = p;
    p->prev = current;
}

// check if original list is sorted or not
int isSorted(struct node *p)
{

    int x = INT_MIN; // check first node's value against min int

    while (p != NULL)
    {
        if (p->data < x) // failure condition: if false, it's not sorted
        {
            printf("\n No, it's not sorted!");
            return 0;
            x = p->data;
            p = p->next;
        }
        printf("\n Yes, it's sorted!");
        return 1;
    }
}

// find number of nodes in list
int count(struct node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

// sum all the elements iteratively
int add()
{
    struct node *p = head;
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    printf("\n Sum of all the elements: %d", sum);
    return (sum);
}

// issue with adding recursively!
int recursiveAdd()
{
    struct node *p;
    if (p == NULL)
        return 0;
    printf("\n Recursive sum is: %d", p->data + recursiveAdd(p->next));
    return recursiveAdd(p->next) + p->data;
}

// max value in ped list
int max(struct node *p)
{
    int max = INT_MIN; //INT_MIN is -2147483648
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    printf("\n Max is: %d", max);
    return max;
}

// max value in ped list
int min(struct node *p)
{
    int min = INT_MAX; //INT_MIN is -2147483648
    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    printf("\n Min is: %d", min);
    return min;
}

// iterative search for head node's key
struct node *search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            printf("\n Key was found: %d", p->data);
            return p;
            p = p->next;
        }
        printf("\n Key searched was not found. The key found was %d.", p->data);
        return NULL;
    }
}

// recursive search for head node's key
struct node *rSearch(struct node *p, int key)
{
    if (p == NULL)
    {
        printf("\n\n Key was not found.");
        return NULL;
    }

    if (key == p->data)
    {
        printf("\n\n Key found recursively as %d", p->data);
        return p;
        return rSearch(p->next, key);
    }
}

// move node to beginning via linear search
struct node *moveSearch(struct node *p, int key)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            printf("\n\n Node's data is %d and was moved to head.", p->data);
            return (p);
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// insert node before head and insert after given position
void insert(struct node *p, int index, int x) //pos means position
{
    struct node *t;
    int i;
    if (index < 0 || index > count(p)) // check if index is valid or not
        return;
    {
        t = (struct node *)malloc(sizeof(struct node)); //create new node called t
        t->data = x;                                    // assign value to node t

        if (index == 0) // steps for inserting before first node
        {
            t->next = head; // modify p 1: point t node to head
            head = t;       // modify p 2: point head to t node
        }
        else
        {
            for (i = 0; i < index - 1; i++) // move node position - 1 times
            {
                p = p->next;
                t->next = p->next;
                p->next = t;
            }
        }
    }
}

void insertLast(int x)
{
    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node))); // create new node t
    t->data = x;                                      // assign value to t's data
    t->next = NULL;                                   // null is after new node

    if (head == NULL)
    { // if no nodes then make new node the head
        head = tail = t;
    }
    else
    {
        tail->next = t; // move last node to t
        tail = t;       // last node is t
    }
}

void sortedInsert(struct node *p, int x)
{
    struct node *t, *q = NULL;
    t = (struct node *)(malloc(sizeof(struct node))); // create new node t
    t->data = x;                                      // assign value to t's data
    t->next = NULL;                                   // after new node is NULL

    if (head == NULL) // if no nodes, then head node is t
    {
        head = t;
    }
    else
    {
        while (p && p->data < x) // when p is not null and p's data is < x
        {                        // Ex: p's data = 8 < 22
            q = p;
            p = p->next; // insert larger num after smaller num for sorted list
        }

        if (p == head) // if only one node, then t's next is the head and head is t
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next; // move t to next, move q to next
            q->next = t;       // q will be moved to t location
        }
    }
}

int delete (struct node *p, int index)
{
    struct node *q; // 2 pointers required
    int x = -1;
    int i; // value to delete is int therefore return type will be int

    if (index < 1 || index > count(p)) // check that indices are valid
        return -1;                     // return -1 for invalid
    if (index == 1)
    {
        q = head;
        x = head->data;    // save head's data before deleting node
        head = head->next; // move head to next
        delete;
        q; // delete q node
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {          // move position - 1 times
            q = p; // q should move to p
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete;
        p;
    }
}

// remove duplicates from SORTED list, will not work for unsorted!!
int removeDuplicate(struct node *p) //first node
{
    struct node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// reverse ped list elements via array
void reverseElements(struct node *p)
{
    int *A, i = 0;
    struct node *q = head; // must have a pointer on head node!!

    A = (int *)malloc(sizeof(int) * count(p)); // get size of ped list
    while (q != NULL)
    {
        A[i] = q->data; //copy q's data to array
        q = q->next;    // move to next q node
        i++;            // increment array index
    }
    q = head; // after elements are in array, start at first pointer p
    i--;      // decrement index to last element

    while (q != NULL)
    {
        q->data = A[i--]; // copy array to ped list q node, decrement index
        q = q->next;      // move to next q node
    }
}

// reverse links to reverse linked list
void reverseLinks(struct node *p)
{
    struct node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

// recursively reverse ped list
void rReverse(struct node *q, struct node *p) // need 2 pointers
{
    if (p != NULL)
    {
        rReverse(p, p->next);
        p->next = q;
    }
    else
    {
        head = q;
    }
}

// concatenate two linked lists
void concat()
{
    struct node *p = head, *q = second; // 2 pointers
    third = p;

    while (head->next != NULL)
        p = head->next;
    head->next = q;
}

// display the list
void printList()
{
    struct node *p = head;

    printf("\n\n [head] <=>");

    //start from the beginning
    while (p->next != NULL)
    {
        printf(" %d <=>", p->data);
        p = p->next;
    }

    printf(" %d <=>", p->data);
    printf(" [head]\n");
}

int main()
{
    create(2);
    create(2); //duplicate
    create(2); //duplicate
    create(4);
    create(8);
    create(10);

    create2(1);
    create2(2);
    create2(3);
    create2(4);
    create2(5);
    create2(6);

    // isSorted(head);

    // insert(head, 0, 6); //insert at position, index, value as integer

    // insertLast(14);
    // insertLast(-7);

    // sortedInsert(head, 9);

    // count(head);

    // add();
    // recursiveAdd();

    // max(head);
    // min(head);

    // search(head, 2); // should be found in the beginning
    // search(head, 4); // should not be found in the beginning

    // rSearch(head, 2);
    // rSearch(head, 0);

    // moveSearch(head, 10);

    // printf("\n Deleted element: %d", delete (head, 2));
    // removeDuplicate(head);

    // reverseElements(head);
    // reversLinks(head);
    // rReverse(NULL, head);

    // printf("concatinated\n");
    printList(head); // list will show 10 as first node b/c of moveSearch function being called

    return 0;
}