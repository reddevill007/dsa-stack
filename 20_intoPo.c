/*
    Converting an infix expression to its postfix counterpart needs you to follow certain steps. The following are the steps:
    -> Start moving left to right from the beginning of the expression.
    -> The moment you receive an operand, concatenate it to the postfix expression string.
    -> And the moment you encounter an operator, move to the stack along with its relative precedence number and see if the topmost operator in the stack has higher or lower precedence. If it's lower, push this operator inside the stack. Else, keep popping operators from the stack and concatenate it to the postfix expression until the topmost operator becomes weaker in precedence relative to the current operator.
    -> If you reach the EOE, pop every element from the stack, and concatenate them as well. And the expression you will receive after doing all the steps will be the postfix equivalent of the expression we were given.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int precedence(char ch)
{
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

char* infixToPostfix(char* infix, int size)
{
    struct stack *sp = (struct stack * ) malloc (sizeof(struct stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char* postfix = (char *)malloc((sp->size + 1) * sizeof(char));

    int i = 0; // Tracks infix traversal
    int j = 0; // Tracks postfix addition

    while (infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
            
        }
        
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    
    postfix[j] = '\0';
    return postfix;
    
}

int main()
{
    char *infix = "a-b+t/6";
    infix = "x-y/z-k*d";
    int length = strlen(infix);
    printf("postfix is %s\n", infixToPostfix(infix, length));
    return 0;
}

