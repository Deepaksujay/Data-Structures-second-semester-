#include <stdio.h>
#include <stdlib.h>

//Write a program to implement a priority queue.

struct queue{
    int data;
    int priority;
    struct queue *next;
};

typedef struct queue p_queue;

p_queue *create(p_queue *root,int element,int priority){
    root = malloc(sizeof(p_queue));
    (root)->data = element;
    (root)->next = NULL;
    (root)->priority = priority;
    return root;
}

p_queue *enque(p_queue *root, int element, int priority){
    if (root == NULL){
        return create(root,element,priority);
    }
    else if (root->priority > priority){
        p_queue *new = create(new,element,priority);
        new->next = root;
        root = new;
    }
    else{
        root->next = enque(root->next,element,priority);
    }
    return root;
}

p_queue *deque(p_queue *root){ //one with the least priority wii be first
    p_queue *dup;
    dup = root;
    if (root->next != NULL){
        root = root->next;
    }
    free(dup);
    return root;
}

void display_(p_queue *root){
    if (root != NULL){
        printf("->(%d,%d)",root->data,root->priority);
        display_(root->next);
    }
}

int main(){

    p_queue *root = NULL;
    root = enque(root,5,2);
    display_(root);
    printf("\n");
    root = enque(root,5,1);
    root = enque(root,15,1);
    display_(root);
    printf("\n");
    root = deque(root);
    display_(root);
    printf("\n");

    return 0;
}