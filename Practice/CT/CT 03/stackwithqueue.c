// make a stack using queue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

struct queue{
    Node *front;
    Node *rear;
};
typedef struct queue Queue;

bool isEmpty(Queue *q){
    if(q->front == NULL) return true;
    else return false;
}

void enqueue(Queue *q, int data){
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

void push(Queue *q, int data){
    enqueue(q, data);
}

int pop(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    if(q->front == q->rear){
        int data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        return data;
    }
    else{
        Node *temp = q->front;
        while(temp->next != q->rear){
            temp = temp->next;
        }
        int data = q->rear->data;
        free(q->rear);
        q->rear = temp;
        q->rear->next = NULL;
        return data;
    }
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main(){
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;

    push(q, 1);
    push(q, 2);
    push(q, 3);

    pop(q);
    pop(q);

    push(q, 4);
    push(q, 5);
    push(q, 6);

    display(q);

}