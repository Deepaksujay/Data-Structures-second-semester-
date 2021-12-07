#include <stdio.h>
//Write a program in C to print all unique elements in an array.

void check_duplicate(int arr[], int no){
    int i,j,k=0,check[no],l,f=0;
    for (i=0;i<no;i++){
        for (j=i+1;j<no;j++){
            if (arr[i] == arr[j]){
                for (l=0;l<f;l++){
                    if (arr[i] == check[l]){
                        break;
                    }
                }
                if (arr[i] != check[l]){
                    check[f] = arr[i];
                    f++;
                    k++;
                    //printf("%d\n",arr[i]);
                }
            }
        }
    }
    printf("The unique elements found in the array are:");
    for(i=0;i<no;i++){
        for(j=0;j<f;j++){
            if(arr[i] == check[j]){
                break;
            }
        }
        if (arr[i] != check[j]){
            printf("%d  ",arr[i]);
        }
    }
    printf("\n");
}

int main(){

    int no;
    printf("Input the number of elements to be stored in the array:");
    scanf("%d",&no);
    int arr[no],i;
    for (i=0;i<no;i++){
        printf("element %d:",i);
        scanf("%d",&arr[i]);
    }
    check_duplicate(arr, no);

    return 0;
}