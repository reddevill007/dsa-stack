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

int main()
{
    top = push(top, 78);
    top = push(top, 8);
    top = push(top, 7);
    traversal(top);
    int element = pop(top);
    printf("Popped element is %d\n", element);
    traversal(top);

    return 0;
}