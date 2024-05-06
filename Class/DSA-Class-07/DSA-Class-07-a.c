// creating Stack in with array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for boolean data type in isFull, isEmpty function

// golbally declared 
// int arraySize = 10;
#define arraySize 10 // making it constant or static variable

struct stack{
    int items[arraySize];
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

void push(Stack *stack, int data){
    if(isFull(stack))
        printf("Stack is full\n");
    else{
        stack->top++;
        stack->items[stack->top] = data; //Data pushed into stack
    }
}

bool isEmpty(Stack *stack){
    if(stack->top == -1)
        return true;
    else
        return false;
}

int pop(Stack *stack){
    if(isEmpty(stack))
        printf("Stack is empty\n");
    else{
        printf("Item popped = %d\n", stack->items[stack->top]);
        stack->top--;
        return stack->items[stack->top+1];
    }
}

void display(Stack *stack){
    if(isEmpty(stack))
        printf("Stack is empty\n");
    else{
        printf("Stack items are:\n");
        for(int i=0; i<=stack->top; i++){
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

void main(){
    // // manually assigned stack
    // int stackItems[arraySize];
    // int top = -1;

    // manually assigned stack
    Stack *stack1 = (Stack*)malloc(sizeof(Stack));
    // stack1->top = -1; // creating empty stack manually

    createEmptyStack(stack1); // creating empty stack using function
    push(stack1, 100);
    printf("after push\n");
    display(stack1);

    push(stack1, 200);
    printf("after push\n");
    display(stack1);

    push(stack1, 300);
    printf("after push\n");
    display(stack1);

    pop(stack1);
    printf("after pop\n");
    display(stack1);

    // push, pop, peek, display in user input way using switch case
    createEmptyStack(stack1);

    int choice, data;

    while(choice != 5){
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(stack1, data);
                break;
            case 2:
                pop(stack1);
                break;
            case 3:
                printf("Top item = %d\n", stack1->items[stack1->top]);
                break;
            case 4:
                display(stack1);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}