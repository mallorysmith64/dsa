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
    else
        printf("\n Recursive sum is: %d", p->data + recursiveAdd(p->next));
        return recursiveAdd(p->next) + p->data;
}

// display the list
void printList()
{
    struct node *ptr = head;

    printf("\n[head] <=>");

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
    printList();
    return 0;
}