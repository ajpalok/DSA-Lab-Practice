#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*left, *right;
};

typedef struct node Node;

void InsertData(Node *node,int key){
    if(node==NULL){
        node=malloc(sizeof(node));
        node->data=key;
        node->left=node->right=NULL;
        return;
    }
    

    if (node->data>key){
        if(node->left==NULL){
            Node *NewNode=malloc(sizeof(NewNode));
            NewNode->left=NewNode->right=NULL;
            NewNode->data=key;
            node->left=NewNode;
        } 
        else InsertData(node->left,key);



    }
    else
    {
        if(node->right==NULL){
            Node*NewNode=malloc(sizeof(NewNode));
            NewNode->left=NewNode->right=NULL;
            NewNode->data=key;
            node->right=NewNode;
        }
        else InsertData(node->right,key);
    }
}

bool search(int key, Node *node){
    while(node->data!=key){
        if(node==NULL){
            return false;
        }
        else{
            if(node->data>key)
            node=node->left;
            else
            node=node->right; 
        
        }

    }
     return true;


}


void DeleteData(Node *node, int key)
{
    if(search(int key,node)){




    }
    else("Can't find the Data", key);
}


void main(){

    Node *root=NULL;
   // Node *root=malloc(sizeof(Node));
    //root->data=root->left=root->right=NULL;
    
    InsertData(root,3);
    InsertData(root,15);
    InsertData(root,6);

    DeleteData(root,15);
}