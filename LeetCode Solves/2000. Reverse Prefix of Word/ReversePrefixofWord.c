#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define arraySize 250

struct stack{
    char items[arraySize];
    int top;
};
typedef struct stack Stack;

void createEmptyStack(Stack *stack){
    stack->top = -1;
}

bool isFull(Stack *stack){
    return stack->top == arraySize - 1;
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

int indexOfCh(char* word, char ch){
    for(int i=0; i<strlen(word); i++){
        if(word[i]==ch) return i;
    }
    return -1; //for not found
}

char* reversePrefix(char* word, char ch) {
    int indexToStop = indexOfCh(word, ch);
    if (indexToStop==-1) return word;

    Stack *stack = malloc(sizeof(Stack));
    createEmptyStack(stack);

    for (int i=0; i<=indexToStop; i++){
        push(stack, word[i]);
    }
    
    for (int i=0; i<=indexToStop; i++){
        word[i]=pop(stack);
    }
    return word;
}

void main(){
    char word1[250] = "abcdefd";
    char ch1 = 'd';
    printf("word 1: %s \n", reversePrefix(word1, ch1));
    char word2[250] = "xyxzxe";
    char ch2 = 'z';
    printf("word 1: %s \n", reversePrefix(word2, ch2));
    char word3[250] = "abcd";
    char ch3 = 'z';
    printf("word 1: %s \n", reversePrefix(word3, ch3));

}