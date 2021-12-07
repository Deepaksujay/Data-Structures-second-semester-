#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

//create-enque-deque-display-count-peek

typedef struct lifo queue;

struct lifo{
    int st[MAXSIZE];
    int rear;
};
int count;

void create(queue *sup){
    sup->rear = -1;
    count = 0;
}

void enque(queue *sup, int data){
    if (sup->rear == MAXSIZE-1){
        printf("Queue overflow\n");
    }
    else {
        int i;
        for(i=count;i>0;i--){
            sup->st[i] = sup->st[i-1];
        }
        sup->st[0] = data;
        sup->rear++;
        count++;
        printf("%d is enqued\n",data);
    }
}

int deque(queue *sup){
    if (sup->rear == -1){
        printf("Queue underflow\n");
    }
    else{
        printf("%d is dequed\n",sup->st[sup->rear]);
        int l = sup->st[sup->rear];
        count--; 
        sup->rear--;
        return l;
    }
    return 0;
}

void display(queue *mi){
    int i;
    printf("count=%d\n",count);
    if (count == 0){
        printf("Queue is empty");
    }
    for (i=0;i<count;i++){
        printf("->%d",mi->st[i]);
    }
    printf("\n");
}

int Count(queue *mai){
    return count;
}

int peek(queue *mai){
    return mai->st[mai->rear];
}

int main(){

    queue mind;
    create(&mind);
    enque(&mind,5);
    display(&mind);
    deque(&mind);
    display(&mind);
    enque(&mind,3);
    display(&mind);
    enque(&mind,52);
    enque(&mind,125);
    display(&mind);
    deque(&mind);
    display(&mind);

    return 0;
}