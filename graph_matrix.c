#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int no = 10;

struct queue{  //linear queue having data and address of next node in queue
    int data;
    struct queue *next;
};

struct bfs{
    int data;
    char colour;
    int d;
    struct bfs *prev;
};

typedef struct bfs bfs;

typedef struct queue queue;

int search_queue(queue *root,int element){//return 0 if there is element in queue else 1
    if (root != NULL){
        if (root->data == element){
            return 0;
        }
        return search_queue(root->next,element);
    }
    return 1;
}

queue *enque_small(queue *root,int element){  //enques given element into queue
    if (root == NULL){
        root = malloc(sizeof(queue));
        root->data = element;
        //printf("\n%d is enqued\n",root->data);
        root->next = NULL;
    }
    else{
        root->next = enque_small(root->next,element);
    }
    return root;
}

queue *enque(queue *root,int element){ //checks whether already the element present in
    if (search_queue(root,element)){ //queue or not. If present doesn't enque
        root = enque_small(root,element);//enques element if it's not there
    }
    return root;
}

int deque(queue **root){  //deques the queue and returns the element that deqeued
    queue *dup;
    dup = *root;
    int val = (*root)->data;
    if((*root)->next == NULL){
        *root = NULL;
    }else{
       *root = (*root)->next; 
    }
    free(dup);
    return val;
}

void display_queue(queue *root){  //displays queue
    if (root != NULL){  //while root is not null displays data and goes for root->next
        printf("->%d",root->data);
        display_queue(root->next);
    }
}

int ele_in_array(int vertex[], int source, int no_v){
    for(int i=0;i<no_v;i++){ 
        if (vertex[i] == source){
            return i;
        }
    }
    return -1;
}

void display_array(int vertex[],int no_v){
    for(int i=0;i<no_v;i++){
        printf("%d, ",vertex[i]);
    }
    printf("\n");
}

int check_1_0r_0(int l){
    if (l==1 || l==0){
        return 1;
    }
    return 0;
}

void bfs_(bfs *vertex[no],int adj[no][no],int source,queue **bfs_q){
    *bfs_q = enque(*bfs_q,source);
    int u;
    printf("%d",(vertex[source])->data);
    while (*bfs_q != NULL){
        u = deque(bfs_q);
        for(int j=0;j<no;j++){
            if (adj[u][j] == 1){
                if ((vertex[j])->colour == 'w'){
                    printf("->%d",(vertex[j])->data);
                    (vertex[j])->colour = 'g';
                    (vertex[j])->d = (vertex[u])->d + 1;
                    (vertex[j])->prev = (vertex[u]);
                    *bfs_q = enque(*bfs_q,j);
                }
            }
        }
        (vertex[u])->colour = 'b';
    }
    printf("\n");
}

void bfs_main(bfs *vertex[],int data[],int adj[no][no]){
    int source_i,i;
    display_array(data,no);
    printf("Please Enter the source element for BFS Traversal: ");
    scanf("%d",&source_i);
    int source = ele_in_array(data,source_i,no);//data[source] = source_i, source is found
    if (source == -1){ //if source is not in vertex run function again
        printf("Please select source from above data\n");
        bfs_main(vertex,data,adj);
        exit(-1);
    }
    for(i=0;i<no;i++){
        vertex[i] = malloc(sizeof(bfs));
        (vertex[i])->data = data[i];
        (vertex[i])->colour = 'w';
        (vertex[i])->prev = NULL;
        (vertex[i])->d = INFINITY;
    }
    (vertex[source])->colour = 'g';
    (vertex[source])->d = 0;
    queue *bfs_q = NULL;
    bfs_(vertex,adj,source,&bfs_q);
    for (i=0;i<no;i++){
        if(vertex[i]->colour == 'w'){
            bfs_(vertex,adj,i,&bfs_q);
        }
    }
}

int main(){

    /*
    printf("Enter no of elements:");
    scanf("%d",&no);
    int data[no];
    for (int i=0 ; i<no ; i++){
        printf("Element - %d : ",i+1);
        scanf("%d",&data[i]);
    }
    int adj[no][no] , i=0 , j=0;
    printf("Press 1 if there is an edge else 0\n");
    for(i=1;i<=no;i++){
        for (j=1;j<no+1;j++){
            printf("node %d - node %d :",i,j);
            scanf("%d",&adj[i][j]);
            if(!check_1_0r_0(adj[i][j])){
                j--;
            }
        }
    }    */

    int data[] = {0,1,2,3,4,5,6,7,8,9};
    int nu = sizeof(data)/sizeof(data[0]);
    bfs *vertex[nu];

    //                      A B C D E F G H I J
    int adj[10][10] =/*A*/{{0,0,0,0,0,0,0,0,1,0,},
                     /*B*/ {0,0,1,1,0,0,0,1,0,1,},
                     /*C*/ {0,1,0,0,1,0,0,0,1,0,},
                     /*D*/ {0,1,0,0,1,1,0,0,0,0,},
                     /*E*/ {0,0,1,1,0,0,0,0,0,0,},
                     /*F*/ {0,0,0,1,0,0,1,0,0,0,},
                     /*G*/ {0,0,0,0,0,1,0,1,0,0,},
                     /*H*/ {0,1,0,0,0,0,1,0,0,0,},
                     /*I*/ {1,0,1,0,0,0,0,0,0,1,},
                     /*J*/ {0,1,0,0,0,0,0,0,1,0,}};




    bfs_main(vertex,data,adj);


    return 0;
}