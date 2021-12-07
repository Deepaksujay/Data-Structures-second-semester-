#include <stdio.h>
#include <stdlib.h>
// Write a program in C to create a singly linked list
// of n nodes and display it in reverse order.

struct linked{
    int data;
    struct linked *next;
};
typedef struct linked node;

node *create (node *root, int element){
    root = (node *)malloc(sizeof(node));
    (root)->data = element;
    root->next = NULL;
    return root;
}

node *insert(node *root, int element){
    if (root == NULL){
        root = create(root,element);
    }
    else if (root->next == NULL){
        node *new;
        root->next = create(new, element);
    }
    else{
        root->next = insert(root->next, element);
    }
    return root;
}

void display(node *root){
    if (root == NULL){
        printf("List is empty");
    }
    else {
        printf("->%d",root->data);
        if (root->next != NULL){
            display(root->next);
        }
    }
}

void display_reverse(node *root){
    if (root->next != NULL){
        display_reverse(root->next);
    } 
    printf("->%d",root->data); 
}

int main(){

    node *root = NULL;
    root = insert(root,10);
    root = insert(root,15);
    root = insert(root,25);
    root = insert(root,9);
    root = insert(root,31);
    root = insert(root,2);
    printf("Straight order:");
    display(root);
    printf("\n");
    printf("Reverse order:");
    display_reverse(root);
    printf("\n");
    return 0;
}