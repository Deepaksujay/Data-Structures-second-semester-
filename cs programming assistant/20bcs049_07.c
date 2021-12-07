#include <stdio.h>
#include <stdlib.h>
//Write a program to implement a circular queue.
//create-enque-deque-display-count-peek
struct queue{
    int data;
    struct queue *next;
};

typedef struct queue queue;

queue *create(queue *root, int element, queue *set){
    if (root == NULL){
        root = malloc(sizeof(queue));
        root->data = element;
        if (set == NULL){
            set = root;
        }
        root->next = set;
    }
    return root;
}

queue *enque(queue *root, int element, queue *set){
    if (root == NULL){
        root = create(root,element,root);
    }
    else if(root->next != set){
        root->next = enque(root->next, element, set);
    }
    else{
        root->next = NULL;
        root->next = create(root->next,element,set);
    }
    return root;
}

void display(queue *root, queue *set){
    if (root != NULL){
        if(root->next != set){
            printf("%d->",root->data);
            display(root->next,set);
        }
        else{
            printf("%d",root->data);
        }
    }
}

int deque(queue **root){ // deletes first element that is in root which is front
    int val;
    if (*root == NULL){
        printf("Queue is empty\n");
        return 0;
    }
    else if ((*root)->next == *root){
        val = (*root)->data;
        queue *dup = *root;
        *root = NULL;
        free(dup);
    }
    else{
        queue *dup;
        dup = *root;
        while (dup->next != (*root)){
            dup = dup->next;
        }
        val = (*root)->data;
        dup->next = (*root)->next;
        dup = (*root);
        (*root) = (*root)->next;
        free(dup);
    }
    return val;
}

int count(queue *root,queue *set){
    if (root->next == set){
        return 1;
    }
    else {
        return 1 + count(root->next,set);
    }
}

int peek(queue *root){
    if (root != NULL){
        return root->data;
    }
    return 0;
}

void display_info(queue *root){  // displays queue,count and peek value
    display(root,root);
    printf("\n");
    printf("Count:%d\n",count(root,root));
    printf("Peek:%d\n",peek(root));
}

int main(){

    queue *root = NULL;
    root = enque(root,5,root);
    root = enque(root,10,root);
    root = enque(root,11,root);
    root = enque(root,12,root);
    display_info(root);
    printf("Dequed:%d\n",deque(&root));
    display_info(root);
    printf("Dequed:%d\n",deque(&root));
    display_info(root);
    root = enque(root,21,root);
    root = enque(root,32,root);
    display_info(root);
    printf("Dequed:%d\n",deque(&root));
    display_info(root);

    return 0;
}