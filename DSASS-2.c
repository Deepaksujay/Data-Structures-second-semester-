#include <stdio.h>
#include <string.h>
 
struct personalBid{
    int valuation;
    int bids;
};

void incsorder(int arr[],int n){    //arrange array arr into inc order 
    int l=1,i;
    while(l){
        l=0;
        for(i=0;i<n-1;i++){
            if (arr[i]>arr[i+1]){
                arr[i+1]=arr[i]+arr[i+1];
                arr[i]=arr[i+1]-arr[i];
                arr[i+1]=arr[i+1]-arr[i];
                l=l+1;
            }
        }
    }
}

int second_high_number(int arr[],int length){  //length=length of the array arr
    int i,max=arr[0],max2=arr[0];               //returns the second highest element in the arr
    for (i=0;i<length;i++){
       if (max<arr[i]){
           max=arr[i];
       }
   }
   for (i=0;i<length;i++){
       if (arr[i]==max){
           continue;
       }
       if (max2<arr[i]){
           max2=arr[i];
       }
   }
   return max2;
}

int maxEleIndex(arr[],int n){//returns index of the max element int the array arr
   int i,ind=0,max=arr[0];      //'n' refers to the total no of elements in array
   for (i=0;i<n;i++){
       if (max<arr[i]){
           max=arr[i];
           ind=i;
       }
   }
   return ind;
}

 int main(){

    int np,n,winnervaluation,winnerpaid,utility,winnerpaid2;//np=total no of persons  n=used in for loop
    printf("Enter no of persons here:");
    scanf("%d",&np);
    struct personalBid players[np];  //np players are declared
    int val[np],bid[np],maxIndex;
    for (n=0;n<np;n++){        //takes input of all persons valuation
        printf("Enter valuation of person %d here:",n+1);
        scanf("%d",&players[n].valuation);
        val[n]=players[n].valuation;

        printf("Enter bid of person %d here:",n+1);     //takes input for all persons bids
        scanf("%d",&players[n].bids);
        bid[n]=players[n].bids;
    }
   
    maxIndex=maxEleIndex(bid,np);  //gives index of the highest bidded person
    winnervaluation=val[maxIndex];  //gives valuation of the highest bidded person
    winnerpaid2=second_high_number(bid,np);//gives amount paid by winner without rearranging
    incsorder(bid,np);
    winnerpaid=bid[np-2];
    printf("Winner evaluation:%d\n",winnervaluation);
    printf("Winner paid:%d\n",winnerpaid2);
    utility=winnervaluation-winnerpaid2;
    printf("Utility of the winner:%d \n",utility);
    


    

    
    return 0;
 }