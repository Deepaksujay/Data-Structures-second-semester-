#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct lifo {
    int value;
    struct lifo *next;
};

typedef struct lifo stack;

void create(stack **top){
    *top=NULL;
}

void push(stack **top, int element){
    stack *new;
    new = (stack*)malloc(sizeof(stack));
    if (new==NULL){
        printf("Stack is full\n");
        exit(-1);
    }
    new->value=element;
    new->next= *top;
    *top= new;
    //printf("Element %d is pushed\n",element);
}

int pop(stack **top){
    if (*top==NULL){
        printf("stack is empty\n");
        exit(-1);
    }
    int t;
    stack *p;
    t=(*top)->value;
    p= *top;
    *top= (*top)->next;
    free (p);
    //printf("Element %d is popped\n",t);
    return t;
}
void display(stack **top){
    stack *duplicate;
    duplicate = *top;
    printf("stack:\n");
    while (duplicate != NULL){
        printf("      %d\n",duplicate->value);
        duplicate= duplicate->next;
    }
}

void q_push(stack **top,int element){
    stack *used;
    create(&used);
    int data;
    while ((*top) != NULL){
        data = pop(top);
        push(&used,data);
    }
    push(top,element);
    while (used != NULL){
        data = pop(&used);
        push(top,data);
    }
}


int main() {
    stack *queue,*hi;
    create(&queue);
    q_push(&queue,7);
    q_push(&queue,8);
    q_push(&queue,9);
    display(&queue);
    create(&hi);
    push(&hi,7);
    push(&hi,8);
    push(&hi,9);
    display(&hi);
    
    return 0;
}