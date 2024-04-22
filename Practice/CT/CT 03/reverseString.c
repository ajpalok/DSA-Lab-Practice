// Take input of string from user and
// then call a split function that will
// split the string into words and then
// reverse the characters of each word and
// then push each characters to a stack.
// Then pop the characters from stack and
// print the reversed word while popping.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node{
    char data;
    struct node *next;
};
typedef struct node Node;

struct stack{
    Node *top; // acting as head of linked list
};
typedef struct stack Stack;

void push(Stack *s, char data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

bool isNotEmpty(Stack *s){
    if (s->top != NULL) return true;
    else return false;
}

char pop(Stack *s){
    if(isNotEmpty(s)){
        Node *temp = malloc(sizeof(Node));
        temp = s->top;
        s->top = s->top->next;
        char character = temp->data;
        free(temp);
        return character;
    }
    else{
        printf("Stack is empty\n");
        return '\0';
    }
}

void main(){
    // take input from user
    printf("Enter a string: "); // to understand what are going to do in cmd
    char str[100];
    // scanf("%s", &str); // to take input but it will take only one word
    fgets(str, sizeof(str), stdin); // to take input from user

    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;

    for(int i = 0; i < strlen(str); i++){
        push(s, str[i]);
    }

    while(isNotEmpty(s)){
        printf("%c", pop(s));
    }
}