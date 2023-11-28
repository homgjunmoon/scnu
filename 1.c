#include <stdio.h>
#define size 5

//삽입
void insert(int arr[]){
  int idx, data;
  int *p;
  p=arr;
  printf("\n인덱스, 값 입력\n");
  scanf("%d %d", &idx, &data);

  for(int i = size-1; i > idx; i--){ //부등호 주의, i가 작아지니까 'i>idx'
    *(p+i) = *(p+(i-1));
  }
  arr[idx] = data;
}
//삭제
void del(int arr[]){
  int idx;
  printf("\n인덱스 입력\n");
  scanf("%d", &idx);
  for(int i = idx; i < size-1; i++){
    arr[i] = arr[i+1];
  }
  arr[size-1] = 0;
}
//출력
void print(int arr[]){
    for(int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}
int main(){
  int num;
  int arr[size] = {1,3,5,7,9};
  int *p1;
  p1 = arr;

  while(1){
    printf("\n1. 삽입 \n");
    printf("2. 삭제 \n");
    printf("3. 출력 \n");
    scanf("%d", &num);
    printf("\n<전>");
    printf("\n인덱스  ");
    for(int i = 0; i<size; i++)
      printf("%d ", i);
    printf("\n값\t");
    for(int i = 0; i<size; i++)
      printf("%d ", *(p1+i));

 switch(num){
      case 1: insert(arr);
      break;
      case 2: del(arr);
      break;
      case 3: print(arr);
      break;
    }
    printf("\n<후>");
    printf("\n인덱스  ");
    for(int i = 0; i<size; i++)
      printf("%d ", i);
    printf("\n값\t");
    for(int i = 0; i<size; i++)
      printf("%d ", *(p1+i));
  }
}
