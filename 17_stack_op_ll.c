#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *tp)
{
    if(tp == NULL)
        return 1;
    return 0;
}

int isFull(struct Node *tp)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL)
        return 1;
    return 0;
}

struct Node* push(struct Node *tp, int x)
{
    if(isFull(tp))
        printf("stack overflow\n");
    else
    {
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = tp;
        tp = n;
        return tp;
    }
}

int pop(struct Node *tp)
{
    if(isEmpty(tp))
        printf("stack underflow\n");
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct Node* ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
        return ptr->data;
    return INT_MIN;
    
}

int stackTop()
{
    return top->data;
}

int stackBottom()
{
    struct Node* ptr = top;
    while (ptr->next != NULL)
        {ptr = ptr->next;}
    return ptr->data; 
}

int main()
{
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);
    traversal(top);

    for (int i = 0; i < 4; i++)
    {
        printf("Value at position %d is: %d\n", i+1, peek(i+1));
    }

    printf("The top most element is %d\n", stackTop());
    printf("The Bottom most element is %d\n", stackBottom());
    

    return 0;
}