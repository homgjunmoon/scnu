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
        printf("�޸� �����÷�");
        return;
    }
    else {
        s->data[(s->top)++] = data;
    }
    prints(s);
}

void pop(STK *s) {
    if(s->top == -1) {
        printf("�޸� ����÷�");
        return;
    }
    else {
        printf("������ �� : %d\n", s->data[--(s->top)]);
    }
    prints(s);
}

void prints(STK *s) {
    printf("���� ���� : ");
    for(int i = 0; i < s->top; i++){
        printf("%d  ", s->data[i]);
    }
}

int main() {

    STK s;
    int num, data;
    init_stack(&s);

    printf("1�� : ����     2�� : ����    3�� : ���α׷� ����  ");
    while(1) {
        printf("\n���ϴ� �۾��� �Է����ּ��� : ");
        scanf("%d", &num);

        if(num == 1) {
            printf("�����ϰ� ���� �����͸� �Է��ϼ��� : ");
            scanf("%d", &data);
            push(&s, data);
        }
        else if(num == 2) {
            pop(&s);
        }
        else if(num == 3){
            printf("���α׷��� �����մϴ�.");
            break;
        }
        else
            printf("�ٽ� �Է����ּ���.");
    }
}
