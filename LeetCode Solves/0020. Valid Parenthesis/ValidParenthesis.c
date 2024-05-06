#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define arraySize 10000

struct stack{
    char items[arraySize];
    int top;
};
typedef struct stack Stack;

void createEmptyStack(Stack *stack){
    stack->top = -1;
}

bool isFull(Stack *stack){
    if(stack->top == arraySize - 1)
        return true;
    else
        return false;
}

void push(Stack *stack, char data){
    if(isFull(stack))
        printf("Stack is full\n");
    else{
        stack->top++;
        stack->items[stack->top] = data;
    }
}

bool isEmpty(Stack *stack){
    // if(stack->top == -1)
    //     return true;
    // else
    //     return false;
    return stack->top == -1;
}

char pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return '\0';
    }
    stack->top--;
    return stack->items[stack->top+1];
}

char peek(Stack *stack){
    if(isEmpty(stack))
        return stack->items[stack->top];
    return '\0';
}

bool isValid(char *s){
    Stack *stack = malloc(sizeof(Stack));
    createEmptyStack(stack);

    for(int i=0; i<strlen(s); i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(stack, s[i]);
            continue;
        }

        char check = peek(stack);
        if (!isEmpty(stack) && ((s[i]==')' && check=='(')||(s[i]=='}' && check=='{')||(s[i]==']' && check=='['))){
            pop(stack);
        }
        else return false;
    }
    return isEmpty(stack);
}