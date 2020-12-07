#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //needed for INT_MIN

// doubly linked list has 2 pointers: next and prev
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL; //global decration of head node
struct node *tail = NULL;
struct node *current = NULL;

// create the list
void insert(int data)
{
    // allocate memory for new node
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->data = data;
    link->prev = NULL;
    link->next = NULL;

    // if head is empty, create a new list
    if (head == NULL)
    {
        head = link;
        return;
    }

    current = head;

    // move to the end of the list
    while (current->next != NULL)
        current = current->next;

    // insert link at the end of the list
    current->next = link;
    tail = link;
    link->prev = current;
}

// find number of nodes in list
int count()
{
    struct node *p = head;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    printf("\n Number of nodes: %d", c);
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

// max value in linked list
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

// max value in linked list
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

// display the list
void printList()
{
    struct node *ptr = head;

    printf("\n\n [head] <=>");

    //start from the beginning
    while (ptr->next != NULL)
    {
        printf(" %d <=>", ptr->data);
        ptr = ptr->next;
    }

    printf(" %d <=>", ptr->data);
    printf(" [head]\n");
}

int main()
{
    insert(2);
    insert(4);
    insert(8);
    insert(10);

    count();

    add();
    recursiveAdd();

    max(head);
    min(head);

    search(head, 2); // should be found in the beginning
    search(head, 4); // should not be found in the beginning

    rSearch(head, 2);
    rSearch(head,0);

    printList();

    return 0;
}