// Parenthesis Matching - Stack using Arrays

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data; // should be type char b/c we have chars in our expression
    struct Node *next;
} *top = NULL;

// if open parenthesis push into stack
void push(char x) // use char type
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full \n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop() // use char type
{
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p; // need one pointer
    p = top;

    while (p != NULL)
    {
        printf("%d ", p->data); // print pointer's data
        p = p->next;            // then move next
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    return top == NULL ? 1 : 0;
}

int main()
{
    char *exp = "((a+b) *(c-d))";

    printf("%d ", isBalanced(exp));

    return 0;
}