// // non circular stack queue fuctionality
// // gcc Class/DSA-Class-08-a.c -o 1 && ./1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define size 5

struct queue
{
    int front,
        rear,
        container[size];
};

typedef struct queue Queue; // typedef = type define // eta datatype define/toiry kore 

bool isEmpty(Queue *queue){
    if(queue->front==-1) return true;
    else return false;
}

bool isFull(Queue *queue){
    if(queue->rear == size-1) return true;
    else return false;
}

void enqueue(Queue *queue, int data){
    if(isFull(queue)){
        printf("OverFlow\n");
        return;
    }
    if(isEmpty(queue)) queue->front = 0;
    ++queue->rear;
    queue->container[queue->rear] = data;
    printf("%d enqueue complete, mubarak hoo\n", data);
}

void dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("UnderFlow\n");
        return;
    }
    if(queue->front == queue->rear && queue->front!=-1){
        printf("%d Pop done\n", queue->container[queue->front]);
        queue->front = queue->rear = -1;
        printf("Stack become empty\n");
        return;
    }
    printf("%d Pop done\n", queue->container[queue->front]);
    queue->front++;
}

void display(Queue *queue){
    printf("Printing Queue data: ");
    for(int i = queue->front; i <= queue->rear; ++i)
        printf("%d ", queue->container[i]);
    puts(""); // printf("\n");
}

void main(){
    // int front, rear, size, queue[size];
    // Data type: "Queue"
    // Queue = sturct Queue

    Queue *q1 = malloc(sizeof(Queue));
    q1->front = q1->rear = -1;
    enqueue(q1, 6);
    enqueue(q1, 7);
    enqueue(q1, 8);
    dequeue(q1);

    display(q1);
}

