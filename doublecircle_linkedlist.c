#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node node;
node *new;

void create (node **main, int element){
    *main = malloc(sizeof(node));
    if (*main == NULL){
        printf("Sorry doubly circular linked list is not created\n");
        exit(-1);
    }
    (*main)->prev = *main;
    (*main)->data = element;
    (*main)->next = *main;
    printf("Circular Doubly Linked List is created\n");
}

void display(node **main){
    node *pre;
    pre = *main;
    if (*main == NULL){
        printf("Sorry doubly circular linked list is empty\n");
        exit(-1);
    }
    if ((*main)->prev == (*main)){
        printf("->%d",(pre)->data);
        printf("\n");
    }
    else {
        printf("%d",(pre)->data);
        while ((pre)->next != *main ){
            (pre) = (pre)->next;
            printf("->%d",(pre)->data);
        }
        printf("\n");
    }
}

void add(node **main, int position, int element){  //Doesn't work for the poisition no one 
    node *pre;
    pre = *main;
    new = malloc(sizeof(node));
    for(int i=2;i<position;i++){
        pre = pre->next;
    }
    new->prev = pre;
    new->data = element;
    new->next = pre->next;
    pre->next = new;
    pre = new->next;
    pre->prev = new;
    printf("Element %d is added at the position %d\n",element,position);
}

void add_start(node **main, int element){
    new = malloc(sizeof(node));
    new->data = element;
    new->next = *main;
    new->prev = (*main)->prev;
    (*main)->prev = new;
    *main = new;
    ((new)->prev)->next = *main;
    printf("Element %d is added to starting of the list\n",element);
}

int len_list(node **main){
    node *ptr;
    ptr = *main;
    int i=1;
    if (*main == NULL){
        printf("list is empty\n");
    }
    if (ptr->next == *main){
        return i;
    }
    else {
        while (ptr->next != *main){
            ptr = ptr->next;
            i++;
        }
    }
    return i;
}

int delete(node **main, int position){
    node *ptr;
    int i, len = len_list(main);
    ptr = *main;
    for(i=1;i<position;i++){
        ptr = ptr->next;
    }
    (ptr->prev)->next = ptr->next;
    (ptr->next)->prev = ptr->prev;
    if (position%len == 1){
        *main = ptr->next;
    }
    i = ptr->data;
    free(ptr);
    printf("Node at the position %d with data '%d' is deleted\n",position,i);
    return i;
}

int main(){
    node *main;
    create (&main,5);
    add_start(&main,23);
    add(&main,2,10);
    display (&main);
    delete(&main,6);
    display (&main);
    add(&main,3,110);
    delete(&main,1);
    display (&main);
    add(&main,2,1110);
    display (&main);

    return 0;
}