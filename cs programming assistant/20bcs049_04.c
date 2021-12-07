#include <stdio.h>
//Write a program in C to store n elements in an 
//array and print the elements using pointer.
int main(){

    int no;
    printf("Input the number of elements to store in the array :");
    scanf("%d",&no);
    int arr[no];
    int *ptr = arr;
    //Input function
    printf("Input %d number of elements in the array :\n",no);
    for (int i=0;i<no;i++){
        printf("element - %d : ",i);
        scanf("%d",(ptr+i));
    }
    //Display function
    printf("The elements you entered are: \n");
    for (int i=0;i<no;i++){
        printf("element - %d : %d\n",i,*(ptr+i));
    }

    return 0;
}