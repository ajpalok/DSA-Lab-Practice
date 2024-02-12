// Linked list topic analysis

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *one = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = malloc(sizeof(struct Node));
    one = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    one->data = 1;
    one->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    head = one;

    
    printf("Initial data in Linked list: \n");
    printList(head);

    // inserting data in first node

    struct Node *newFirstNode = malloc(sizeof(struct Node));
    newFirstNode->data = 0;
    newFirstNode->next = one;
    head = newFirstNode;

    printf("After inserting data in first node: \n");
    printList(head);

    // inserting data in last node
    struct Node *newLastNode = malloc(sizeof(struct Node));
    newLastNode->data = 4;
    newLastNode->next = NULL;

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newLastNode;

    printf("After inserting data in last node: \n");
    printList(head);

    // inserting data in middle node in possition 2

    int possition;
    printf("Enter possition (from 1-6): ");
    scanf("%d", &possition);

    struct Node *newMiddleNode = malloc(sizeof(struct Node));
    newMiddleNode->data = 5;
    newMiddleNode->next = NULL;

    temp = head;
    for (int i = 1; i < possition - 1; i++)
    {
        temp = temp->next;
    }
    newMiddleNode->next = temp->next;
    temp->next = newMiddleNode;

    printf("After inserting data in %d node: \n", possition);
    printList(head);

    // Delete Data from first node
    temp = head;
    head = head->next;
    free(temp);

    printf("After deleting data from first node: \n");
    printList(head);

    // Delete Data from last node

    temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);

    printf("After deleting data from last node: \n");
    printList(head);

    // Delete Data from middle node in possition user input possition

    printf("Enter possition (from 1-5): ");
    scanf("%d", &possition);

    temp = head;
    prev = NULL;
    for (int i = 1; i < possition; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);

    printf("After deleting data from %d node: \n", possition);
    printList(head);

    // search data in linked list
    int search;
    printf("Enter data to search: ");
    scanf("%d", &search);

    temp = head;
    bool isFound = false;
    while (temp != NULL)
    {
        if (temp->data == search)
        {
            isFound = true;
            break;
        }
        temp = temp->next;
    }

    if (isFound)
    {
        printf("Data found in linked list\n");
    }
    else
    {
        printf("Data not found in linked list\n");
    }


    return 0;
}
