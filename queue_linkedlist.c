#include <stdio.h>
#include <stdlib.h>

//create-enque-deque-display-count-peek

struct leave{
    int element;
    struct leave *next;
};

typedef struct leave queue;

int count=0;

queue  *rear;

void create (queue **lifo, int data){ //creates queue
    (*lifo)->element = data;
    (*lifo)->next = NULL;
    rear = *lifo;
    count++;
    printf("Queue is created with element %d\n",data);
}

void enque (queue **lifo, int data){
    queue *new = malloc(sizeof(queue));
    new->element = data;
    new->next = NULL;
    rear->next = new;
    rear = new;
    count++;
    printf("%d was enqued\n",data);
}

int deque (queue **lifo){
    if (*lifo == NULL){
        printf("stack is empty\n");
        exit(-1);
    }
    queue *bin;
    int l = (*lifo)->element;
    bin = *lifo;
    *lifo = (*lifo)->next;
    bin->next = NULL;
    //free(bin);
    printf("Element %d was dequed\n",l);
    count--;
    return l;
}

void display(queue **lifo){
    queue *dup;
    printf("size of queue is %d\n",count);
    dup = *lifo;
    printf("%d",dup->element);
    dup = dup->next;
    while(dup != NULL){
        printf("<-%d",dup->element);
        dup = dup->next;
    }
    printf("\n");
}

int Count(queue **lifo){
    return count;
}

int Count_r(queue **lifo){
    queue *dup;
    dup = *lifo;
    int l=0;
    while(dup != NULL){
        l++;
        dup = dup->next;
    }
    return l;
}

int peek(queue **lifo){
    return (*lifo)->element;
}

int main(){

    queue *mind;
    create (&mind,5);
    display(&mind);
    enque(&mind,10);
    display(&mind);
    deque(&mind);
    display(&mind);
    enque(&mind,34);
    enque(&mind,17);
    enque(&mind,107);
    display(&mind);
    deque(&mind);
    display(&mind);

    return 0;
}