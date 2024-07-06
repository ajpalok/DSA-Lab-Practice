// Solving linked list problems ,Taking name as input 

#include <stdio.h>

struct Node{
    char name[100];
    int id;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void main(){


    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Node *one;
    struct Node *two;
    struct Node *three;

    one = malloc(sizeof(struct Node));
    two =malloc(sizeof(struct Node));
    three = malloc(sizeof(struct Node));
}