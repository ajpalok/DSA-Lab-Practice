#include <stdio.h>
#include <stdlib.h>

struct double_linked_list_node {
    int data;
    struct double_linked_list_node *next;
    struct double_linked_list_node *prev;
};
typedef struct double_linked_list_node node;

node *head = NULL;
node *tail = NULL;

void insertion(node *new_node) {
    // If the list is empty
    if (head == NULL) {
        head = new_node;
        tail = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    }
}

void deletion(node *node_to_delete) {
    if (node_to_delete == head) {
        head = head->next;
        if (head != NULL) // If list is not empty
            head->prev = NULL;
        else
            tail = NULL; // Update tail if list becomes empty
    } else if (node_to_delete == tail) {
        tail = tail->prev;
        if (tail != NULL) // If list is not empty
            tail->next = NULL;
        else
            head = NULL; // Update head if list becomes empty
    } else {
        node_to_delete->prev->next = node_to_delete->next;
        node_to_delete->next->prev = node_to_delete->prev;
    }
    free(node_to_delete);
}

void search(int value) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value found in the list\n");
            return;
        }
        temp = temp->next;
    }
    printf("Value not found in the list\n");
}

void traversal() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void size_count() {
    int count = 0;
    node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Size of the list is: %d\n", count);
}

int main() {
    node *one = (node *)malloc(sizeof(node));
    node *two = (node *)malloc(sizeof(node));
    node *three = (node *)malloc(sizeof(node));
    node *four = (node *)malloc(sizeof(node));
    node *five = (node *)malloc(sizeof(node));
    
    one->data = 1;
    one->prev = NULL;
    one->next = two;

    two->data = 2;
    two->prev = one;
    two->next = three;

    three->data = 3;
    three->prev = two;
    three->next = four;

    four->data = 4;
    four->prev = three;
    four->next = five;

    five->data = 5;
    five->prev = four;
    five->next = NULL;

    head = one;
    tail = five;

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = 6;
    new_node->prev = NULL;
    new_node->next = NULL;

    insertion(new_node);

    deletion(two);

    search(3);

    traversal();

    size_count();

    return 0;
}
