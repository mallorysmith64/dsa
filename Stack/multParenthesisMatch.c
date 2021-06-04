#include <stdio.h>
#include <stdlib.h>
#define bool int

// structure of a stack node
struct node
{
    char data;
    struct node *next;
};

// Function to push an item to stack
void push(struct node **top_ref, int new_data);

// Function to pop an item from stack
int pop(struct node **top_ref);

bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

bool areBracketsBalanced(char exp[])
{
    int i = 0;

    // Declare an empty character stack
    struct node *stack = NULL;

    // transverse and check if brackets are matching
    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack, exp[i]); // if open bracket, push to stack

        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (stack == NULL)
                return 0;

            else if (!isMatchingPair(pop(&stack), exp[i]))
                return 0;
        }
        i++;
    }

    if (stack == NULL)
        return 1; // stack is empty, brackets match
    else
        return 0;
}

int main()
{
    char exp[100] = "{()}[]";

    if (areBracketsBalanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}

// Function to push an item to stack
void push(struct node **top_ref, int new_data)
{
    // allocate node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Stack overflow n");
        getchar();
        exit(0);
    }

    // put in the data
    new_node->data = new_data;

    // link the old list off the new node
    new_node->next = (*top_ref);

    // move the head to point to the new node
    (*top_ref) = new_node;
}

// Function to pop an item from stack
int pop(struct node **top_ref)
{
    char res;
    struct node *top;

    // If stack is empty then error
    if (*top_ref == NULL)
    {
        printf("Stack overflow n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}