#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}
 
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

int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    return 0;
}
 
int parenthesisMatch(char * exp, int size){
    // Create and initialize the stack
    // struct stack* sp;
    struct stack *sp = (struct stack * ) malloc (sizeof(struct stack));
    sp->size = size;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){
                return 0;
            }
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }    
}

int main()
{
    char * exp = "[4-6]((8){(9-8)})";
    int length = strlen(exp);
    
    // Check if stack is empty
    if(parenthesisMatch(exp, length)){
        printf("The parenthesis is matching\n");
    }
    else{
        printf("The parenthesis is not matching\n");
    }
    return 0;
}
