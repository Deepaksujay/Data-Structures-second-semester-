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
    printf("Element %d is pushed\n",element);
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
    printf("Element %d is popped\n",t);
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


int main(){

    stack *top;
    create (&top);
    push(&top,5);
    push(&top,4);
    push(&top,2);
    push(&top,10);
    display(&top);
    pop(&top);
    push(&top,109);
    display(&top);


    return 0;
}