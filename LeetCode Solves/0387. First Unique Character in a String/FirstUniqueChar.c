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
    if(q->front == NULL) return true;
    else return false;
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

bool search(Queue *q, char data){
    Node *temp = q->front;
    while(temp != NULL){
        if(temp->data == data) return true;
        temp = temp->next;
    }
    return false;
}

int searchwithcount(Queue *q, char data){
    Node *temp = q->front;
    int count = 0;
    while(temp != NULL){
        if(temp->data == data) count++;
        temp = temp->next;
    }
    return count;
}

int firstUniqChar(char* s) {
    if (s == NULL) return -1;
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    
    // s pointer contains characters of the string which are going to be enqueued in the queue if not repeated
    for(int i = 0; i<strlen(s)-1; i++){
        enqueue(q, s[i]);
    }
    if (isEmpty(q)) return -1;
    else{
        for(int i = 0; i<strlen(s)-1; i++){
            if(searchwithcount(q, s[i]) == 1) return i;
        }
        return -1;
    }
}

void main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("First unique character in the string is at index: %d\n", firstUniqChar(str));
    
}