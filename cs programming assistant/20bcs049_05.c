#include <stdio.h>
#include <stdlib.h>
/*Create a doubly linked list of integers. Delete a given integer from 
the above doubly linkedlist. Display the contents of the above list 
after deletion. */

struct linked{
    int data;
    struct linked *prev,*next;
};
typedef struct linked node;

node *insert(node *root, int element){
    if (root == NULL){
        root = malloc(sizeof(node));
        root->next = root->prev = NULL;
        root->data = element;
    }
    else if (root->next == NULL){
        node *new;
        new = malloc(sizeof(node));
        new->data = element;
        root->next = new;
        new->prev = root;
        new->next = NULL;
    }
    else{
        root->next = insert(root->next,element);
    }
    return root;
}

node *delete(node *root, int element){
    if (root == NULL){
        printf("List is empty\n");
    }
    else if (root->data == element){
        if (root->prev == NULL){
            node *del = root;
            root = root->next;
            free(del);
        }
        else if (root->next == NULL){
            (root->prev)->next = NULL;
            free(root);
            return 0;
        }
        else {
            node *del = root;
            (root->prev)->next = root->next;
            (root->next)->prev = root->prev;
            root = root->next;
            free(del);
        }
    }
    else if(root->next != NULL){
        root->next = delete(root->next, element);
    }
    else{
        printf("Element is not present in the list\n");
    }
    return root;
}

void display(node *root){
    if (root == NULL){
        printf("List is empty\n");

    }
    else{
        printf("->%d",root->data);
        if (root->next != NULL){
            display(root->next);
        }
    }
}

int main(){

    node *root = NULL;
    root = insert(root,8);
    root = insert(root,18);
    root = insert(root,28);
    root = insert(root,4);
    display(root);
    printf("\n");
    root = delete(root,18);
    display(root);
    printf("\n");

    return 0;
}