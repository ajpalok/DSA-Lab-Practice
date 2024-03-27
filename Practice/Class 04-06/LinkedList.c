// Linked-list
// We are learning linked list by assigning data Manually...
// 
// We need with 2 data:
// 1) The Data we want to store
// 2) The address of next Node


#include<stdio.h>
#include<stdlib.h> // For Memory Allocation (MALLOC())

struct Node
{
    int data;
    struct Node *next_node_address;
};

// Making a printing function.
void printFunction(struct Node *head){
    // While the node don't gives is null, this iteration (loop) continues...
    // When the node gives NULL, the List ends there. So,
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next_node_address;
    }
}

int main(){
    // We are declaring head variable as a starting point of traversing linked-list.
    struct Node *head = NULL;
    head = malloc(sizeof(struct Node));

    // Assigning data manually
    // Making empty nodes
    struct Node *one=NULL;
    struct Node *two=NULL;
    struct Node *three=NULL;

    one=malloc(sizeof(struct Node));
    two=malloc(sizeof(struct Node));
    three=malloc(sizeof(struct Node));

    // For Node one
    one->data = 100;
    one->next_node_address = two; // to access the next node after this node one 

    // For Node two
    two->data = 200;
    two->next_node_address = three; // to access the next node after this node two

    // For Node three
    three->data = 300;
    three->next_node_address = NULL; // here the list ends, so next address is NULL

    head = one; // We are assigning full node one in head as a starting node to traverse the linked list

    // printing the linked-list
    printf("Initial Data from Linked-List:\n");
    printFunction(head);
    puts(""); // just to moving into new line in console

    // Here we are going to start inserting nodes in linked list
    // 
    // Adding new node before first node...

}