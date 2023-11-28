#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

typedef struct STK{
    int top;
    int data[SIZE];
}STK;

void init_stack(STK *s) {
    s->top = 0;
}

void push(STK *s, int data) {
    if(s->top == SIZE) {
        printf("메모리 오버플로");
        return;
    }
    else {
        s->data[(s->top)++] = data;
    }
    prints(s);
}

void pop(STK *s) {
    if(s->top == -1) {
        printf("메모리 언더플로");
        return;
    }
    else {
        printf("삭제된 값 : %d\n", s->data[--(s->top)]);
    }
    prints(s);
}

void prints(STK *s) {
    printf("현재 스택 : ");
    for(int i = 0; i < s->top; i++){
        printf("%d  ", s->data[i]);
    }
}

int main() {

    STK s;
    int num, data;
    init_stack(&s);

    printf("1번 : 삽입     2번 : 삭제    3번 : 프로그램 종료  ");
    while(1) {
        printf("\n원하는 작업을 입력해주세요 : ");
        scanf("%d", &num);

        if(num == 1) {
            printf("삽입하고 싶은 데이터를 입력하세요 : ");
            scanf("%d", &data);
            push(&s, data);
        }
        else if(num == 2) {
            pop(&s);
        }
        else if(num == 3){
            printf("프로그램을 종료합니다.");
            break;
        }
        else
            printf("다시 입력해주세요.");
    }
}
