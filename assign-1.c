#include <stdio.h>


int main(){
  
  int arr[] = {10, 20, 30, 40, 50},i;
  int *ptr;
  ptr = arr;
  for (i=0;i<5;i++){
      printf("address of arr[%d]:%d\n",i,&arr[i]);
  }
  printf("ptr:%d\n",ptr);
  printf("ptr++:%d\n",ptr++);
  printf("ptr+1:%d\n",ptr+1);
  printf("*ptr:%d\n",*ptr);
  printf("*(ptr+1):%d\n",*(ptr+1));
  printf("*(ptr)+1:%d\n",*(ptr)+1);
  printf("*ptr++:%d\n",*ptr++);
  printf("*ptr--:%d\n",*ptr--);
  printf("*++ ptr:%d\n",*++ ptr);
  printf("*-- ptr:%d\n",*-- ptr);
  printf("(* ptr)++:%d\n",(* ptr)++);
  printf("(* ptr)—-:%d\n",(* ptr)--);
  printf("(*( ptr + 2))++:%d\n",(*( ptr + 2))++);
  printf("(*( ptr + 2))--:%d\n",(*( ptr + 2))--);

  return 0;
}