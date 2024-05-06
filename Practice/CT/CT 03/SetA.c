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
    if(stack->top == -1)
        return true;
    else
        return false;
}

char pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return '\0';
    }
    else{
        stack->top--;
        return stack->items[stack->top+1];
    }
}

char peek(Stack *stack){
    if(stack->top!=-1)
        return stack->items[stack->top];
    return '\0';
}

bool isValidParenthesis(char *s){
    Stack *stack = malloc(sizeof(Stack));
    createEmptyStack(stack);
    printf("%s", s);

    for(int i=0; i<strlen(s)-1; i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(stack, s[i]);
            continue;
        }

        char topOpeningBracket = peek(stack);
        if (!isEmpty(stack) &&((s[i]==')' && topOpeningBracket=='(')||(s[i]=='}' && topOpeningBracket=='{')||(s[i]==']' && topOpeningBracket=='['))){
            pop(stack);
        }
        else return false;
    }
    return isEmpty(stack);
}

void main(){
    char s[100];
    printf("Enter Parenthesis string to validate: ");

    fgets(s, sizeof(s), stdin);

    if (isValid(s)) printf("Valid Parenthesis");
    else printf("Invalid Parenthesis");
}
