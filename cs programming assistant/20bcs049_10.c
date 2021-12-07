#include <stdio.h>
#include <stdlib.h>
//Write a program to convert a Binary tree into its Mirror Tree.

struct tree{
    int data;
    struct tree *left,*right;
};

typedef struct tree tree;

tree *create(tree *root, int num){
    if (root == NULL){
        root = malloc(sizeof(tree));
        root->data = num;
        root->right = root->left = NULL;
    }
    return root;
}

tree *insert (tree *root,int num1,int num2,int ref){ //ref= desired parent of num1&num2
    if (root != NULL){
        if (root->data == ref){
            if (num1 < num2){
                root->left = create(root->left,num1);
                root->right = create(root->right,num2);
            }
            else if(num1 > num2){
                root->left = create(root->left,num2);
                root->right = create(root->right,num1);
            }
        }
        else{
            insert(root->right,num1,num2,ref);
            insert(root->left,num1,num2,ref);
        }
    }
    return root;
}

void display_in(tree *root){
    if (root != NULL){
        display_in(root->left);
        printf("%d-",root->data);
        display_in(root->right);
    }
}

void display_pre(tree *root){
    if (root != NULL){
        printf("%d-",root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}

void display_post(tree *root){
    if (root != NULL){
        display_post(root->left);
        display_post(root->right);
        printf("%d-",root->data);
    }
}

tree *mirror(tree *root){
    if (root != NULL){
        mirror(root->right);
        mirror(root->left);
        tree *cross = root->right;
        root->right = root->left;
        root->left = cross;
    }
    return root;
}

int main(){

    tree *root = NULL;
    root = create(root,1);
    root = insert(root,2,3,1);
    root = insert(root,4,5,2);
    root = insert(root,6,7,3);

    printf("pre-order:");
    display_pre(root);
    printf("\n");
    printf("In-order:");
    display_in(root);
    printf("\n");
    printf("post-order:");
    display_post(root);
    printf("\n");

    //mirroring the tree
    root = mirror(root);
    printf("Tree is mirrored\n");
    printf("pre-order:");
    display_pre(root);
    printf("\n");
    printf("In-order:");
    display_in(root);
    printf("\n");
    printf("post-order:");
    display_post(root);
    printf("\n");


    return 0;
}