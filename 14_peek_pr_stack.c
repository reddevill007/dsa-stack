#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size; // size of stack
    int top;  // pointer to topmost element
    int *arr;
};

// Checks if stack is empty or not
int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

// Checks if stack is full or not
int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Can't push %d to the stack\n", val);
    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
        return INT_MIN;
    }

    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not the valid positonfor the stack");
        return INT_MIN;
    }
    return ptr->arr[arrayInd];
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}

int main()
{
    // Struct pointer
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("The value at position %d is %d\n", i, peek(s, i));
    }

    printf("The top most value of this stack is %d\n", stackTop(s));
    printf("The bottom most value of this stack is %d\n", stackBottom(s));
    

    return 0;
}