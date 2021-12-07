#include <stdio.h>
#include <stdlib.h>
//insertion-deletion-searching-findmax-findmin
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

int search(tree *root, int element){
    if (root == NULL){
        return 0;
    }
    else if ((root)->data == element){
        return 1;
    }
    else if ((root)->data > element){
        return search((root)->left,element);
    }
    else if ((root)->data < element){
        return search((root)->right,element);
    }
    return 1;
}

tree* max_left_node(tree *root){//finds max node in the tree with root as root
    if (root->right == NULL){
        return root;
    }
    else{
        return max_left_node(root->right);
    }
}

tree* remove_node(tree *root, int element){
    if (root->data > element){
        root->left = remove_node(root->left,element);
    }
    else if (root->data < element){
        root->right = remove_node(root->right, element);
    }
    else if (root->data == element){
        if (root->right == NULL){
            tree *new = root->left;
            free(root);
            return new;
        }
        else if (root->left == NULL){
            tree *new = root->right;
            free(root);
            return new;
        }
        else {
            tree *new = max_left_node(root->left);
            root->data = new->data;
            root->left = remove_node(root->left, new->data);
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

int max_element(tree *root){
    if (root->right != NULL){
        return max_element(root->right);
    }
    else{
        return root->data;
    }
}

int min_element(tree *root){
    if (root->left != NULL){
        return min_element(root->left);
    }
    else{
        return root->data;
    }
}

tree* pre_tree_full(tree *root){
    int no,i;
    printf("Enter the number of elements:");
    scanf("%d",&no);
    int pre[no];
    printf("Enter each element and hit enter before entering next\n");
    for (i=0;i<no;i++){
        scanf("%d",&pre[i]);
    }
    for (i=0;i<no;i++){
        root = insert(root, pre[i]);
    }
    return root;
}

tree* post_tree_full(tree *root){
    int no,i;
    printf("Enter the number of elements:");
    scanf("%d",&no);
    int pre[no];
    printf("Enter each element and hit enter before entering next\n");
    for (i=no-1;i>=0;i--){
        scanf("%d",&pre[i]);
    }
    for (i=0;i<no;i++){
        root = insert(root, pre[i]);
    }
    return root;
}

int main(){

    tree *root = NULL;
    int i,k=1,in=1;
    
    printf("Do you want to construct tree from following methods?\n");
    printf("1. Pre-order traversal\n");
    printf("2. Post-order traversal\n");
    printf("3. No, I don't want to\n");
    printf("Enter your choice here:");
    
    while(in){
        scanf("%d",&i);
        switch(i){
            case 1:
                root = pre_tree_full(root);
                in=0;
                break;
            case 2:
                root = post_tree_full(root);
                in=0;
                break;
            case 3:
                printf("Proceeding forward\n");
                in = 0;
                break;
            default:
                printf("Please enter valid choice:");
                break;
        }
    }
    
    while (k){
        printf("What function do you want to execute on Binary Search Tree:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search an element\n");
        printf("4. Display Pre-order form of tree\n");
        printf("5. Display In-order form of tree\n");
        printf("6. Display Post-order form of tree\n");
        printf("7. Display Maximum element in tree\n");
        printf("8. Display Minimum element in tree\n");
        printf("9. Exit from the program\n");
        printf("Enter your choice here:");
        scanf("%d",&i);

        switch(i){
            case 1:
                printf("Please enter the element you want to insert:");
                scanf("%d",&in);
                root = insert(root, in);
                printf("%d is inserted into BST succesfull\n",in);
                break;
            case 2:
                if (root == NULL){
                    printf("Sorry, the BST is empty.\n");
                    break;
                }
                printf("Please enter the element you want to delete:");
                scanf("%d",&in);
                if (search(root, in)){
                    root = remove_node(root, in);
                    printf("%d is deleted from BST succesfull\n",in);
                }
                else{
                    printf("Sorry element is not present\n");
                } 
                break;  
            case 3:
                printf("Please enter the element you want to search:");
                scanf("%d",&in);
                if (search(root, in)){
                    printf("%d is present in BST\n",in);
                }
                else{
                    printf("Sorry, %d is not there\n",in);
                }
                break;
            case 4:
                if (root == NULL){
                    printf("Sorry, the BST is empty.\n");
                    break;
                }
                display_pre(root);
                printf("\n");
                break;
            case 5:
                if (root == NULL){
                    printf("Sorry, the BST is empty.\n");
                    break;
                }
                display_in(root);
                printf("\n");
                break;
            case 6:
                if (root == NULL){
                    printf("Sorry, the BST is empty.\n");
                    break;
                }
                display_post(root);
                printf("\n");
                break;
            case 7:
                if (root == NULL){
                    printf("Sorry, the BST is empty.\n");
                    break;
                }
                printf("Maximum element from the BST:%d \n",max_element(root));
                break;
            case 8:
                if (root == NULL){
                    printf("Sorry, the BST is empty.\n");
                    break;
                }
                printf("Minimum element from the BST:%d \n",min_element(root));
                break;
            case 9:
                k=0;
                break;
            default:
                printf("Please select valid choice\n");
                break;
        }
    }

    return 0;
}