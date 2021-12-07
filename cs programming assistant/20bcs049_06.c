#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//Write a program to evaluate a postfix expression.

struct lifo {
    float value;
    struct lifo *next;
};

typedef struct lifo stack;

void create(stack **top){
    *top=NULL;
}

stack *push(stack *top,float element){
    stack *new;
    new = malloc(sizeof(stack));
    if (new==NULL){
        printf("Stack is full\n");
        exit(-1);
    }
    new->value=element;
    new->next= top;
    top= new;
    //printf("Element %c is pushed\n",element);
    return top;
}

float pop(stack **top){
    if (*top == NULL){
        printf("Expression is not valid\n");
        exit(-1);
    }
    float t;
    stack *p;
    t=(*top)->value;
    p= *top;
    if ((*top)->next != NULL){
        *top= (*top)->next;
    }
    else{
        *top = NULL;
    }
    free (p);
    //printf("%c",t);
    return t;
}

int check_op(char l){
    if (l == '^' || l == '*' || l == '/' || l == '+' || l == '-'){
        return 1;
    }
    else {
        return 0;
    }
}

float input(){
    stack *Opera = NULL;
    char ex[100];
    printf("Enter expression here:");
    scanf("%s",ex);
    int len = strlen(ex) , i ;
    float change , value = 0;
    if(check_op(ex[0])){
        printf("First symbol can't be an operator\n");
        exit(-1);
    }
    for (i=0;i<len;i++){
        if (check_op(ex[i])){
            float l = pop(&Opera) , m = pop(&Opera) ;
            if(ex[i] == '+'){
                value = (m + l);
                Opera = push(Opera,value);
            }
            else if(ex[i] == '-'){
                value = (m - l);
                Opera = push(Opera,value);
            }
            else if(ex[i] == '*'){
                value = (m * l);
                Opera = push(Opera,value);
            }
            else if(ex[i] == '/'){
                value = (m / l);
                Opera = push(Opera,value);
            }
            else if(ex[i] == '^'){
                value = pow(m,l);
                Opera = push(Opera,value);
            }
            printf("Value:%f(%f%c%f)\n",value,m,ex[i],l);
        }
        else{
            change = ex[i] - '0';
            if (change > 9 || change < 0){
                printf("Enter valid expression\n");
                exit(-1);
            }
            Opera = push(Opera,change);
        }
    }
    pop(&Opera);
    if (Opera != NULL){
        printf("Enter valid expression\n");
        exit(-1);
    }
    return value;
}

int main(){
    float value = input();
    printf("Value of the postfix expression is: %f\n",value);
    return 0;
}
