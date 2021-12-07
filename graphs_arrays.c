#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct graph{  // graph struct for Bfs of a graph
    char colour;  //color of the node
    int data; //data in the node
    int d;   //level of the node with the level of sorce being 0
    struct graph *prev;  //address of prev node of this with level l-1 with l being level of
                        //this node
};

struct graph_DFS{
    char colour;
    int data;
    int d;
    int f;
    struct graph_DFS *prev;
};

struct queue{  //linear queue having data and address of next node in queue
    int data;
    struct queue *next;
};

typedef struct queue queue;

typedef struct graph_DFS graph_DFS;

typedef struct graph graph;

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

//below programmes returns the indice of the number source in the array vertex.
//else if it's not present in the array it returns -1
//here no_v represents the no of elements in the array vertex
int ele_in_array(int vertex[], int source, int no_v){
    for(int i=0;i<no_v;i++){ 
        if (vertex[i] == source){
            return i;
        }
    }
    return -1;
}

int Get_len_ofArray(int data[]){
    int i = 0;
    while(data[i] != '\0'){
        i += 1;
    }
    return i ;
}

//this function displays the elements in the given array
//here no_v represents no of elements in the array
void display_array(int vertex[],int no_v){
    for(int i=0;i<no_v;i++){
        printf("%d, ",vertex[i]);
    }
    printf("\n");
}

//Displays the BFS traversal of the given graph
//it firsts takes input of source from the user
void BFS_display(graph *vertex[],graph **edges[][2],int data[], int no_v,int no_e){
    int source_i;
    display_array(data,no_v);
    printf("Please Enter the source element for BFS Traversal:");
    scanf("%d",&source_i);
    int source = ele_in_array(data,source_i,no_v);//data[source] = source_i, source is found
    if (source == -1){ //if source is not in vertex run function again
        printf("Please select source from above data\n");
        BFS_display(vertex,edges,data,no_v,no_e);
        exit(-1);
    }//vertex array is initialized here i.e it's data,colour etc.
    //white(w) is not visited, grey(g) is processing, black(b) is for processed nodes.
    for(int i=0;i<no_v;i++){
        vertex[i] = malloc(sizeof(graph));
        (vertex[i])->data = data[i];
        (vertex[i])->colour = 'w';
        (vertex[i])->prev = NULL;
        (vertex[i])->d = INFINITY; 
    }
    //source becomes gray as it is processing and d=0 as it source and prev is NULL
    (vertex[source])->colour = 'g';
    (vertex[source])->d = 0;
    (vertex[source])->prev = NULL;
    queue *bfs = NULL;
    bfs = enque(bfs,source);//source is enqued into the queue, here source is index of source_i
    int u,i;  // u = present source i.e index of vertex array that's being processed
    printf("%d",(vertex[source])->data);
    //below loop sturcture: source->adjacent_1->adjacent_2...and so on followed by
    //->(adjacent_1)_1->(adjacent_1)_2..and so on followed by adjacents of 
    //adjacent_2 . Remember that repeated elements are filtered out and doesn't 
    //occur again
    while (bfs != NULL){
        i=0;
        u = deque(&bfs);
        for(i=0;i<no_e;i++){
            if((*(edges[i][0]))->data == (vertex[u])->data){
                if ((*(edges[i][1]))->colour == 'w'){
                    //printf("Entered %d - %c\n",(*(edges[i][1]))->data,(*(edges[i][1]))->colour);
                    printf("->%d",(*(edges[i][1]))->data);
                    (*(edges[i][1]))->colour = 'g';
                    (*(edges[i][1]))->d = (vertex[u])->d + 1;
                    (*(edges[i][1]))->prev = (vertex[u]);
                    bfs = enque(bfs,ele_in_array(data,(*(edges[i][1]))->data,no_v));
                }
            }
        }
        (vertex[u])->colour = 'b';
    }
    printf("\n");
}

void DFS_small(graph_DFS *vertex[],graph_DFS **edges[][2],int data[],int *time,int source,int no_v,int no_e){
    //printf("->%d",vertex[source]->data);
    vertex[source]->d = *time;
    for (int i=0;i<no_e;i++){
        if ((*(edges[i][0]))->data == vertex[source]->data){
            if((*(edges[i][1]))->colour == 'w'){
                (*(edges[i][1]))->colour = 'g';
                printf("->%d",(*(edges[i][1]))->data);
                *time += 1;
                DFS_small(vertex,edges,data,time,ele_in_array(data,(*(edges[i][1]))->data,no_v),no_v,no_e);
            }
        }
    }
    vertex[source]->colour = 'b';
    *time += 1;
    vertex[source]->f = *time;
}

void DFS_display(graph_DFS *vertex[],graph_DFS **edges[][2],int data[], int no_v,int no_e){
    int source_i;
    display_array(data,no_v);
    printf("Please Enter the source element for DFS Treversal:");
    scanf("%d",&source_i);
    int source = ele_in_array(data,source_i,no_v);//data[source] = source_i, source is found
    if (source == -1){ //if source is not in vertex run function again
        printf("Please select source from above data\n");
        DFS_display(vertex,edges,data,no_v,no_e);
        exit(-1);
    }//vertex array is initialized here i.e it's data,colour etc.
    //white(w) is not visited, grey(g) is processing, black(b) is for processed nodes.
    for(int i=0;i<no_v;i++){
        vertex[i] = malloc(sizeof(graph));
        (vertex[i])->data = data[i];
        (vertex[i])->colour = 'w';
        (vertex[i])->prev = NULL;
        (vertex[i])->d = INFINITY; 
        (vertex[i])->f = INFINITY;
    }
    vertex[source]->colour = 'g';
    vertex[source]->d = 0;
    int time = 0;
    printf("%d",vertex[source]->data);
    DFS_small(vertex,edges,data,&time,source,no_v,no_e);
    printf("\n");
    for (int i=0;i<no_v;i++){
        if (vertex[i]->colour == 'w'){
           printf("%d",vertex[i]->data);
           DFS_small(vertex,edges,data,&time,i,no_v,no_e); 
           printf("\n");
        }
    }
}

int main(){

    //This is the elements in the graph
    int data[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int l_data = sizeof(data)/sizeof(data[0]); //l_data is len of array data

    //v[l_data] stores info of all elements for BFS
    graph *v[l_data];
    graph_DFS *v_[l_data];
    //v[0] = v[1] = v[2] = v[3] = v[4] = v[5] = v[6] = v[7] = v[8] = v[9] = NULL;

    //edges store theis edges
    //for example if thers is {v[i],v[i+3]} then it is said that there is connection 
    //from v[i] to v[i+3] that is unidirectional : v[i]->v[i+3]
    //to make it birection two should be included as {v[i],v[i+3]} & {v[i+3],v[i]}
    //including two times says that it is bidirection or else it will unidirectional
    graph **edges[][2] =   {{&v[0],&v[8]},
                            {&v[1],&v[2]},{&v[1],&v[3]},{&v[1],&v[7]},{&v[1],&v[9]},
                            {&v[2],&v[1]},{&v[2],&v[4]},{&v[2],&v[8]},
                            {&v[3],&v[1]},{&v[3],&v[4]},{&v[3],&v[5]},
                            {&v[4],&v[2]},{&v[4],&v[3]},
                            {&v[5],&v[3]},{&v[5],&v[6]},
                            {&v[6],&v[5]},{&v[6],&v[7]},
                            {&v[7],&v[1]},{&v[7],&v[6]},
                            {&v[8],&v[0]},{&v[8],&v[2]},{&v[8],&v[9]},
                            {&v[9],&v[1]},{&v[9],&v[8]},
                            {&v[10],&v[11]},{&v[10],&v[0]}};

    graph_DFS **edges_[][2] =  {{&v_[0],&v_[8]},
                                {&v_[1],&v_[2]},{&v_[1],&v_[3]},{&v_[1],&v_[7]},{&v_[1],&v_[9]},
                                {&v_[2],&v_[1]},{&v_[2],&v_[4]},{&v_[2],&v_[8]},
                                {&v_[3],&v_[1]},{&v_[3],&v_[4]},{&v_[3],&v_[5]},
                                {&v_[4],&v_[2]},{&v_[4],&v_[3]},
                                {&v_[5],&v_[3]},{&v_[5],&v_[6]},
                                {&v_[6],&v_[5]},{&v_[6],&v_[7]},
                                {&v_[7],&v_[1]},{&v_[7],&v_[6]},
                                {&v_[8],&v_[0]},{&v_[8],&v_[2]},{&v_[8],&v_[9]},
                                {&v_[9],&v_[1]},{&v_[9],&v_[8]},
                                {&v_[10],&v_[11]},{&v_[10],&v_[0]}};
    
    
    int l_edge = sizeof(edges)/(2*sizeof(edges[0][0]));
    //l_edge is len of the rows in the array edge i.e no of edges in graph
    
    BFS_display(v,edges,data,l_data,l_edge);
    DFS_display(v_,edges_,data,l_data,l_edge);

    // int hii;
    // printf("Enter element:");
    // scanf("%d",&hii);
    // printf("v[%d]->d:::   %d\n",hii,v[hii]->d);
    // printf("v[%d]->f:::   %d\n",hii,v[hii]->f);


    
    

    return 0;
}