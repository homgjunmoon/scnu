#include <stdio.h>
#define size 5

//����
void insert(int arr[]){
  int idx, data;
  int *p;
  p=arr;
  printf("\n�ε���, �� �Է�\n");
  scanf("%d %d", &idx, &data);

  for(int i = size-1; i > idx; i--){ //�ε�ȣ ����, i�� �۾����ϱ� 'i>idx'
    *(p+i) = *(p+(i-1));
  }
  arr[idx] = data;
}
//����
void del(int arr[]){
  int idx;
  printf("\n�ε��� �Է�\n");
  scanf("%d", &idx);
  for(int i = idx; i < size-1; i++){
    arr[i] = arr[i+1];
  }
  arr[size-1] = 0;
}
//���
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
    printf("\n1. ���� \n");
    printf("2. ���� \n");
    printf("3. ��� \n");
    scanf("%d", &num);
    printf("\n<��>");
    printf("\n�ε���  ");
    for(int i = 0; i<size; i++)
      printf("%d ", i);
    printf("\n��\t");
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
    printf("\n<��>");
    printf("\n�ε���  ");
    for(int i = 0; i<size; i++)
      printf("%d ", i);
    printf("\n��\t");
    for(int i = 0; i<size; i++)
      printf("%d ", *(p1+i));
  }
}
