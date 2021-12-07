#include <stdio.h>
#include <string.h>

struct family_tree{
    char name[30];
    int M_status;
    char wife[30];
    struct family_tree *left,*right;
} *root_dad_family, *root_mom_family;

/* My family tree....:   () represents their partner  , left is elder and right is younger
                                Dad side
                            grandpa - (grandma)
                dad-(mom)                             uncle-(aunt)
                   me                                   cousin 

                                Mom side
                            grandpa - (grandma)
                aunt-(uncle)    mom-(dad)   aunt       uncle
                  cousin           me
*/

typedef struct family_tree family_tree;

family_tree *insert(family_tree *root,char name[30],int mari,
    char wife[30], int no){
        strcpy(root->name, name);
        if (mari){
            strcpy(root->wife, wife);
        }
        root->M_status = mari;
        if (no == 0){
            root->left = root->right = NULL;
        }
        else if (no == 1){
            root->right = NULL;
        }
        return root;
}

int main(){

    root_dad_family = insert(root_dad_family, "VenkateshwarRao", 1, "Subbulu", 2);
    

    return 0;
}