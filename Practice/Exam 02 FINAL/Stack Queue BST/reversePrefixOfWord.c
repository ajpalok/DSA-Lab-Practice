#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define arraySize 250

// here is the codes of stack - start
struct stack{
    char data[arraySize];
    int top;
};
typedef struct stack Stack;

void createEmptyStack(Stack *stack){
    stack->top = -1;
}

void push(Stack *stack, char character){
    if(stack->top==arraySize-1) return;
    stack->top++;
    stack->data[stack->top] = character;
}

char pop(Stack *stack){
    if (stack->top == -1) return '\0';
    char returningData = stack->data[stack->top];
    stack->top--;
    return returningData;
}
// here is the codes of stack - end

int indexDetect(char *word, char ch){
    for (int i=0; i<strlen(word); i++) if(word[i]==ch) return i;
    return -1;
}

char *reversePrefix(char *word, char ch){
    int indexToReverse = indexDetect(word, ch);
    // if the ch is not available in word
    if(indexToReverse == -1) return word;

    // stack declaration needed
    Stack *stack = malloc(sizeof(Stack));
    createEmptyStack(stack);
    // stack declaration needed

    for (int i=0; i<=indexToReverse; i++){
        push(stack, word[i]);
    }
    for (int i=0; i<=indexToReverse; i++){
        word[i] = pop(stack);
    }

    return word;
}

void main(){
    char word[arraySize], ch;

    printf("Enter the string: ");
    fgets(word, sizeof(word), stdin);

    printf("Enter the Character: ");
    scanf("%c", &ch);

    // word = &word[0]
    // reversePrefix(word, ch)
    printf("Result: %s", reversePrefix(word, ch));
}
