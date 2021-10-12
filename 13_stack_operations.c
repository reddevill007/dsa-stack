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
    if(isFull(ptr))
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
    if(isEmpty(ptr))
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

    printf("Popped %d element from the stack\n", pop(s));
    printf("Popped %d element from the stack\n", pop(s));
    printf("Popped %d element from the stack\n", pop(s));
    printf("Popped %d element from the stack\n", pop(s));

    return 0;
}