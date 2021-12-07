#include <stdio.h>
#include <stdlib.h>
//Write a program to count the number of leaf
// and non-leaf nodes in a binary search tree.
struct tree{
    int data;
    struct tree *left,*right;
};

typedef struct tree tree;

tree *insert (tree *root, int num){
    if (root == NULL){
        tree *new;
        new = malloc(sizeof(tree));
        new->data = num;
        new->right = new->left = NULL;
        return new;
    }
    else if (root->data == num){
        printf("Data already exists\n");
    }
    else if (root->data < num){
        root->right = insert (root->right, num);
    }
    else if (root->data > num){
        root->left = insert (root->left, num);
    }
    return root;
}

tree* pre_tree_full(tree *root , int pre[] , int no){
    int i;
    for (i=0;i<no;i++){
        root = insert(root, pre[i]);
    }
    return root;
}

int no_leaf_nodes(tree *root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL & root->right == NULL){
        //printf("%d\n",root->data);
        return 1;
    }
    return no_leaf_nodes(root->left) + no_leaf_nodes(root->right);
}

int no_non_leaf_nodes(tree *root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL & root->right == NULL){
        return 0;
    }
    else{
        //printf("%d\n",root->data);
        return no_non_leaf_nodes(root->left) + no_non_leaf_nodes(root->right) + 1;
    }
}

int main(){
/*                    Binary Tree
                          15
              7                       20
        2           9           17          30
                18  --  14              25  --   35
    leaf-nodes = [2,18,14,17,25,35] - 6 in total
    non leaf-nodes = [15,7,9,20,30] - 5 in total
*/

    tree *root = NULL;
    int pre[11] = {15,7,2,9,8,14,20,17,30,25,35};  //enter the pre-order traversal of tree
    root = pre_tree_full(root,pre,11);
    printf("Total no of leaf nodes of the tree : %d\n",no_leaf_nodes(root));
    printf("Total no of non leaf nodes of the tree : %d\n",no_non_leaf_nodes(root));

    return 0;
}