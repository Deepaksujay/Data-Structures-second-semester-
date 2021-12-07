#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct lifo stack;

struct lifo{
    int st[MAXSIZE];
    int top;
};


void create(stack *s){
    s->top = -1;
}

void push (stack *s, int element)
{
   if (s->top == (MAXSIZE-1)){
    printf ("\n Stackoverflow");
    exit(-1);
   }
   else{
    s->top++;
    s->st[s->top] = element;
   }
   printf("Element %d is pushed\n",element);
}

int pop (stack *s){
   if (s->top == -1){
    printf ("\n Stackunderflow");
    exit(-1);
   }
   else{
       printf("Element %d is popped\n",s->st[s->top]);
       return (s->st[s->top--]);
   }
}

int isempty (stack *s){
   if (s->top == -1){
    return 1;
   }
   else{
    return (0);
   }
}

int isFull (stack *s){
   if (s->top == MAXSIZE-1){
    return 1;
   }
   else{
    return (0);
   }
}

void display(stack *s){
    int i;
    printf("stack:\n");
    for (i=s->top;i>=0;i--){
        if(s->top==-1){
            printf("stack is empty\n");
            exit(-1);
        }
        printf("      %d \n",s->st[i]);
    }
    
}

int len_stack(stack *s){
    return (s->top)+1;
}

int main()
{
   stack s;
   create(&s);
   push(&s,7);
   push(&s,2);
   push(&s,3);
   push(&s,1);
   pop(&s);
   printf("size of the stack:%d \n",len_stack(&s));
   display(&s);
   return 0;
}

