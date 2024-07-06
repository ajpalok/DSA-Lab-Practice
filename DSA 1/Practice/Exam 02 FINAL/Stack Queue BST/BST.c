#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node Node;

Node *insertData(Node *root, int key){
    if(root==NULL){
        root = malloc(sizeof(Node));
        root->left = root->right = NULL;
        root->data=key;
        return root;
    }
    if (root->data > key) root->left = insertData(root->left, key);
    else root->right = insertData(root->right,key);
    return root;
}

bool searchData(Node *root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (root->data > key) return searchData(root->left, key);
    else return searchData(root->right, key);
}

void deleteData(Node *root, int key){
    if(!searchData(root,key)) return;

    Node *temp = malloc(sizeof(Node));

    temp = root;

    while (temp->data != key){
        if (temp->data > key) temp = temp->left;
        else temp = temp->right;
    }

    // for no child
    if (temp->left == NULL && temp->right == NULL){
        temp=NULL;
        return;
    }
    // for one child
    if (temp->left!=NULL && temp->right==NULL){
        temp=temp->left;
        return;
    }
    if(temp->left==NULL && temp->right!=NULL){
        temp=temp->right;
        return;
    }

    //for two or more
    Node *successorFinder = malloc(sizeof(Node));
    successorFinder = temp->right;
    while (successorFinder->left != NULL) successorFinder = successorFinder->left;
    temp->data = successorFinder->data;
    successorFinder = successorFinder->right;
}

void printPostOrder(Node *root) {
    if (root == NULL) // Check if the root is NULL
        return;

    // Traverse left subtree
    printPostOrder(root->left);

    // Traverse right subtree
    printPostOrder(root->right);

    // Print the data of the current node
    printf("%d ", root->data);
}

void printPreOrder(Node *root) {
    if (root == NULL) // Check if the root is NULL
        return;

    // Print the data of the current node
    printf("%d ", root->data);

    // Traverse left subtree
    printPreOrder(root->left);

    // Traverse right subtree
    printPreOrder(root->right);
}

void printInOrder(Node *root) {
    if (root == NULL) // Check if the root is NULL
        return;

    // Traverse left subtree
    printInOrder(root->left);

    // Print the data of the current node
    printf("%d ", root->data);

    // Traverse right subtree
    printInOrder(root->right);
}

void main(){
    Node *root = NULL;

    bool run = true;

    int option;

    while(run){
        printf("Option 1: Insert Data in Tree\n");
        printf("Option 2: Delete Data from Tree\n");
        printf("Option 3: Search Data in Tree\n");
        printf("Option 4: In Order Traversal\n");
        printf("Option 5: Pre Order Traversal\n");
        printf("Option 6: Post Order Traversal\n");
        printf("Option 7: I Quit\n");

        scanf("%d", &option);

        int data;
        switch(option){
            case 1:
                printf("Give the Number: ");
                scanf("%d", &data);
                root = insertData(root,data);
                break;
            case 2:
                printf("Give the Number: ");
                scanf("%d", &data);
                deleteData(root,data);
                break;
            case 3:
                printf("Give the Number: ");
                scanf("%d", &data);
                searchData(root,data);
                break;
            case 4:
                printf("\nInOrder: ");
                printInOrder(root);
                printf("\n\n");
                break;
            case 5:
                printf("\nPreOrder: ");
                printPreOrder(root);
                printf("\n\n");
                break;
            case 6:
                printf("\npostOrder: ");
                printPostOrder(root);
                printf("\n\n");
                break;
            case 7:
                run=false;
                break;
            default:
                break;
        }
    }
}