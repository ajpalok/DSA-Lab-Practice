// circular stack queue fuctionality

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define size 5

struct queue
{
    int front,
        rear,
        container[size];
};

typedef struct queue Queue;

bool isFull(Queue *q){
    if((q->front==0 && q->rear==size-1) || q->front == q->rear+1) return true;
    return false;
}

bool isEmpty(Queue *q){
    if(q->front==-1) return true;
    return false;
}

void enqueue(Queue *q, int data){
    if(isFull(q)){
        printf("Overflow\n");
        return;
    }
    
    if(isEmpty(q)){
        q->front=q->rear=0;
        q->container[q->rear] = data;
        printf("Enqueued %d\n", data);
        return;
    }
    if(q->rear==size-1){
        q->rear=0;
        q->container[q->rear] = data;
        printf("Enqueued %d\n", data);
        return;
    }
    q->rear++;
    q->container[q->rear] = data;
    printf("Enqueued %d\n", data);
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("UnderFlow\n");
        return;
    }
    printf("Dequeued %d\n", q->container[q->front]);
    if(q->front==q->rear) q->front = q->rear = -1;
    else if(q->front==size-1) q->front = 0;
    else q->front++;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Empty Queue\n");
        return;
    }
    int i = q->front;

    while(true){
        printf("%d ", q->container[i]);
        if(i==q->rear) break;
        if(i==size-1) i=0;
        else i++;
    }
}

void main(){
    Queue *q1 = malloc(sizeof(Queue));
    q1->front = q1->rear = -1;

    enqueue(q1, 100);
    enqueue(q1, 200);
    enqueue(q1, 300);
    enqueue(q1, 400);
    enqueue(q1, 500);
    enqueue(q1, 600);
    
    dequeue(q1);
    dequeue(q1);


    display(q1);
}