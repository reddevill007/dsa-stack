/*
    
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack{
    int size; // size of stack
    int top; // pointer to topmost element
    int *arr;
};

// Checks if stack is empty or not
int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1){
        return 1;
    }

    return 0;
}

// Checks if stack is full or not
int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size - 1){
        return 1;
    }

    return 0;
}

int main()
{
    struct stack s;
    s.size = 80;
    s.top = -1;
    s.arr = (int *) malloc(s.size * sizeof(int));

    // Struct pointer 
    struct stack *spoint;
    spoint->size = 80;
    spoint->top = -1;
    spoint->arr = (int *) malloc(spoint->size * sizeof(int));

    // pushing element manually
    spoint->arr[0] = 4;
    spoint->top++;

    if(isEmpty(spoint)){
        printf("The stack is empty\n");
    }

    else
    {
        printf("The stack is not empty\n");
    }
    
    
    return 0;
}