#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lifo {
    char value;
    struct lifo *next;
};

typedef struct lifo stack;

void create(stack **top){
    *top=NULL;
}

void push(stack **top,char element){
    stack *new;
    new = malloc(sizeof(stack));
    if (new==NULL){
        printf("Stack is full\n");
        exit(-1);
    }
    new->value=element;
    new->next= *top;
    *top= new;
    //printf("Element %c is pushed\n",element);
}

char pop(stack **top){
    char t;
    stack *p;
    t=(*top)->value;
    p= *top;
    *top= (*top)->next;
    free (p);
    //printf("%c",t);
    return t;
}
void display(stack **top){
    stack *duplicate;
    duplicate = *top;
    printf("stack:\n");
    while (duplicate != NULL){
        printf("      %c\n",duplicate->value);
        duplicate= duplicate->next;
    }
}

char peak(stack **s){
    return ((*s)->value);
}

int in(char l){
    if (l == '^'){
        return 3;
    }
    if (l == '*' || l == '/'){
        return 2;
    }
    if (l == '+' || l == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int check_op(char l){
    if (l == '^' || l == '*' || l == '/' || l == '+' || l == '-'){
        return 1;
    }
    else {
        return 0;
    }
}

void input(stack **Opera){
    char ex[100];
    printf("Enter expression here:");
    scanf("%s",ex);
    int len = strlen(ex) , i , re = 0;
    for (i=0;i<len;i++){
        if(check_op(ex[i])){
            if (in(ex[i]) > re){
                push(Opera,ex[i]);
                re = in(peak(Opera));
            }
            else if (in(ex[i]) <= re){
                while(in(ex[i]) <= re){
                    printf("%c",pop(Opera));
                    re = in(peak(Opera));
                }
                push(Opera,ex[i]);
                re = in(peak(Opera));
            }
        }
        else if(ex[i] == '('){
            push(Opera,ex[i]);
            re = in(peak(Opera));
        }
        else if(ex[i] == ')'){
            while (peak(Opera) != '('){
                printf("%c",pop(Opera));
            }
            if (peak(Opera) == '('){
                    pop(Opera);
            }
            re = in(peak(Opera));
        }
        else {
            printf("%c",ex[i]);
        }
    }
    while(peak(Opera) != '\0'){
        if(check_op(peak(Opera))){
            printf("%c",pop(Opera));
        }
        else{
            pop(Opera);
        }
    }

}

int main(){
    stack *Opera;
    input(&Opera);
    printf("\n");
    return 0;
}
