// make a queue with stack
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

struct stack{
    Node *top;
};
typedef struct stack Stack;

void push(Stack *s, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

bool isNotEmpty(Stack *s){
    if (s->top != NULL) return true;
    else return false;
}

int pop(Stack *s){
    if(isNotEmpty(s)){
        Node *temp = malloc(sizeof(Node));
        temp = s->top;
        s->top = s->top->next;
        int data = temp->data;
        free(temp);
        return data;
    }
    else{
        printf("Stack is empty\n");
        return -1;
    }
}

void enqueue(Stack *s1, int data){
    push(s1, data);
}

int dequeue(Stack *s1, Stack *s2){
    if(!isNotEmpty(s1) && !isNotEmpty(s2)){
        printf("Queue is empty\n");
        return -1;
    }
    if(!isNotEmpty(s2)){
        while(isNotEmpty(s1)){
            push(s2, pop(s1));
        }
    }
    return pop(s2);
}

void display(Stack *s1, Stack *s2){
    if(!isNotEmpty(s1) && !isNotEmpty(s2)){
        printf("Queue is empty\n");
        return;
    }
    if(!isNotEmpty(s2)){
        while(isNotEmpty(s1)){
            push(s2, pop(s1));
        }
    }
    Node *temp = s2->top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main(){
    Stack *s1 = malloc(sizeof(Stack));
    Stack *s2 = malloc(sizeof(Stack));
    s1->top = s2->top = NULL;

    enqueue(s1, 1);
    enqueue(s1, 2);
    enqueue(s1, 3);
    enqueue(s1, 4);
    enqueue(s1, 4);
    printf(" dequeued: %d\n", dequeue(s1, s2));
    enqueue(s1, 4);
    enqueue(s1, 4);
    printf(" dequeued: %d\n", dequeue(s1, s2));

    display(s1, s2);
}