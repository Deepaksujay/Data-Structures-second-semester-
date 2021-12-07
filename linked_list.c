#include <stdio.h>
#include <stdlib.h>

struct node{
    int element;
    struct node *next;
};

typedef struct node node;
node *new;

void insert_end(node **nodde,int value){
    node *prev;
    new = malloc(sizeof(node));
    if (new==NULL || (*nodde)==NULL){
        printf("Cant perform the task\n");
        exit(-1);
    }
    (new)->element = value;
    (new)->next = NULL;
    prev= *nodde;
    while((*nodde)->next!=NULL){
        *nodde = (*nodde)->next;
    }
    (*nodde)->next = new;
    *nodde = prev;
}

void insert_start(**nodde,int data){
    new = malloc(sizeof(node));
    if (new==NULL || (*nodde)==NULL){
        printf("Cant perform the task\n");
        exit(-1);
    }
    new->next = *nodde;
    new->element = data;
    *nodde = new;
}

void create_node(node **p,int value){
    *p = malloc(sizeof(node));
    (*p)->element=value;
    (*p)->next=NULL;
}

int len_linkedlist(node **nodde){
    int i=1;
    node *duplicate;
    duplicate = *nodde;
    while((duplicate)->next!=NULL){
        duplicate = (duplicate)->next;
        i++;
    }
    return i;
}

void display(node **top){
    node *duplicate;
    duplicate = *top;
    while (duplicate != NULL){
        printf("->%d",duplicate->element);
        duplicate= duplicate->next;
    }
    printf("\n");
}

void insert_middle(node **nodde,int position, int data){
    if ((position<2)||(position>(len_linkedlist(nodde)+1))){
        printf("use proper position\n");
        exit(-1);
    }
    if (new==NULL || (*nodde)==NULL){
        printf("Cant perform the task\n");
        exit(-1);
    }
    new = malloc(sizeof(node));
    new->element = data;
    node *ptr;
    ptr = *nodde;
    for (int i=2;i<position;i++){
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

void deletion_end(node **nodde){
    node *ptr,*last_2; 
    ptr = *nodde;
    while ((ptr)->next != NULL){
        last_2 = ptr;
        ptr = ptr->next;
    }
    last_2->next = NULL;
    free(ptr);
}

void deletion_start(node **nodde){
    node *ptr;
    ptr = *nodde;
    (*nodde) = (*nodde)->next;
    ptr->next = NULL;
    free(ptr);
}

void deletion_middle(node **nodde, int position){
    node *ptr,*prev;
    ptr = *nodde;
    if ((position<2)||(position>(len_linkedlist(nodde)+1))){
        printf("use proper position\n");
        exit(-1);
    }
    for (int i=1;i<position;i++){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
}

void main(){

    node *main;
    create_node(&main,10);
    insert_end(&main,5);
    display(&main);
    insert_start(&main,6);
    display(&main);
    insert_middle(&main,2,8);
    display(&main);   
    deletion_end(&main);
    display(&main);
    deletion_start(&main);
    display(&main);
    insert_end(&main,15);
    insert_middle(&main,3,8);
    display(&main);
    deletion_middle(&main,4);
    display(&main);

}