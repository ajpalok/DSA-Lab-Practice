#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node{
    char data;
    struct node *next;
};
typedef struct node Node;

struct queue{
    Node *front;
    Node *rear;
};
typedef struct queue Queue;

bool isEmpty(Queue *q){
    return q->front == NULL;
}

void enqueue(Queue *q, char data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = NULL;
    }
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
}

int stringToNumber(char c){
    switch (c){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}

int incrimental(int a, int b, int target){
    // return 11 for additional
    // return 12 for multiplicable
    // return 0 for not workable 
}

int decremental(int a, int b, int target){

}

char** addOperators(char* num, int target, int* returnSize) {
    
}

void main(){
    char c;
    scanf("%c", &c);
    printf("%d",stringToNumber(c));
}