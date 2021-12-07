#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *new, *last;

typedef struct node circular_node;

void create(circular_node **list,int value){
    *list = malloc(sizeof(circular_node));
    if (*list == NULL){
        printf("sorry memory is not allocated\n");
        exit(-1);
    }
    (*list)->data = value;
    (*list)->next = *list;
    last = *list;
    printf("circular node is created\n");
}

void display(circular_node **list){
    circular_node *ptr;
    ptr = *list;
    printf("%d",ptr->data);
    ptr = ptr->next;
    while (ptr != *list){
        printf("->%d",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void add_starting(circular_node **list, int element){
    new = malloc(sizeof(circular_node));
    new->data = element;
    new->next = *list;
    (last)->next = new; 
    *list = new;
    printf("Element %d is added to the starting of the list\n",element);
}

void add_ending(circular_node **list, int element){
    new = malloc(sizeof(circular_node));
    new->data = element;
    last->next = new;
    new->next = *list;
    last = new;
    printf("Element %d is added to the ending of the list\n",element);
}

void add_middle(circular_node **list, int position, int element){
    new = malloc(sizeof(circular_node));
    new->data = element;
    if (position < 2){
        printf("Use position more than 1\n");
        exit(-1);
    }
    for (int i=2; i<position; i++){
        (*list) = (*list)->next;
    }
    new->next = (*list)->next;
    (*list)->next = new;
    *list = last->next;
    printf("Element %d is added at the position %d of the list\n",element,position);
}

void deletion_start(circular_node **nodde){
    circular_node *ptr;
    ptr = *nodde;
    (*nodde) = (*nodde)->next;
    ptr->next = NULL;
    last->next = *nodde;
    free(ptr);
    printf("Starting node is deleted\n");
}

void deletion_end(circular_node **nodde){
    circular_node *ptr;
    ptr = *nodde;
    while(ptr->next != last){
        ptr = ptr->next;
    }
    last = ptr;
    ptr = ptr->next;
    last->next = *nodde;
    ptr->next = NULL;
    free(ptr);
    printf("Ending node is deleted\n");
}

void deletion_middle(circular_node **nodde, int position){
    circular_node *ptr,*prev;
    ptr = *nodde;
    if (position<2){
        printf("use proper position\n");
        exit(-1);
    }
    for (int i=1;i<position;i++){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    printf("node at the position %d of the list is deleted\n",position);
}

int len_linkedlist(circular_node **nodde){
    int i=1;
    circular_node *duplicate;
    duplicate = *nodde;
    while((duplicate)->next!=*nodde){
        duplicate = (duplicate)->next;
        i++;
    }
    return i;
}

int main(){
    circular_node *main;
    create (&main,5);
    display(&main);
    add_starting(&main, 10);
    add_ending(&main, 198);
    display(&main);
    deletion_end(&main);
    display(&main);
    add_starting(&main, 110);
    add_ending(&main, 19);
    display(&main);
    deletion_middle(&main,4);
    display(&main);
    add_ending(&main, 129);
    display(&main);

    return 0;
}
