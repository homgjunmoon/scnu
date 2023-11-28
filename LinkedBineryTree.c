#include <stdio.h>
#include <stdlib.h>
#define DataType int //궁금증 1. typedef int DataType과 차이점..?

//이진 트리 노드 구조 정의
typedef struct Tnode {
    struct Tnode *left; //왼쪽 자식 노드를 가리키는 포인터
    DataType data; //노드의 데이터
    struct Tnode *right; //오른쪽 자식 노드를 가리키는 포인터
} Tnode;

typedef struct LinkedBT {
    Tnode *root; // 루트 노드를 가리키는 포인터
} LinkedBT;

//트리 초기화
void init_BT(Tnode **root) {
    *root = NULL; //노드를 NULL로 초기화
}
// 트리 항목 출력 함수
void print_BT(Tnode *root) {
    // 트리를 순회하며 항목 출력
}
//왼쪽 자식 노드 설정 함수
// child를 노드 root의 왼쪽 서브트리로 설정
void set_left(Tnode *root, Tnode *child) {
    if (root->left) {//왼쪽 서브트리가 이미 존재하는 경우
        printf("왼쪽 서브트리가 이미 존재합니다.\n");
        exit(1);
    }
    else {
        root->left = child;//왼쪽 자식 노드를 설정
    }
}
//왼쪽 자식 노드 설정 함수
// child를 노드 root의 오른쪽 서브트리로 설정
void set_right(Tnode *root, Tnode *child) {//오른쪽 서브트리가 이미 존재하는 경우
    if (root->right) {
        printf("오른쪽 서브트리가 이미 존재합니다.\n");
        exit(1);
    }
    else {
        root->right = child;//오른쪽 자식 노드를 설정
    }
}
// 단말 노드 판단 함수
int is_leaf(Tnode *node) {
    //왼쪽, 오른쪽 자식 노드가 모두 없으면 단말 노드
    return !node->left && !node->right;
}
// 노드 데이터 반환
DataType get_data(Tnode *node) {
    if (!node) {
        printf("널 노드이므로 데이터를 반환할 수 없습니다.\n");
        exit(1);
    }
    else {
        return node->data;//노드의 데이터 반환
    }
}
//노드의 부모 노드 반환
Tnode *get_parent(Tnode *root) {
// 부모 노드를 가리키는 필드를 추가하여 구현
}

//노드의 왼쪽 자식 노드를 반환
Tnode *get_left(Tnode *node) {
    return node->left;//노드의 왼쪽 자식 노드 반환
}

//노드의 오른쪽 자식 노드 반환
Tnode *get_right(Tnode *node) {
    return node->right;//노드의 오른쪽 자식 노드 반환
}

int main() {
    LinkedBT IBT1, IBT2;
    Tnode *node1 = (Tnode *)malloc(sizeof(Tnode));//노드 동적 할당
    Tnode *node2 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node3 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *l, *r;//왼쪽, 오른쪽 자식 노드를 가리키는 포인터 선언
    //노드1의 데이터 설정 및 자식 노드 NULL 초기화
    node1->data = 10; node1->left = node1->right = NULL;
     //노드2의 데이터 설정 및 자식 노드 NULL 초기화
    node2->data = 20; node2->left = node2->right = NULL;
     //노드3의 데이터 설정 및 자식 노드 NULL 초기화
    node3->data = 30; node3->left = node3->right = NULL;

    init_BT(&(IBT1.root)); // 트리1 초기화
    IBT1.root = node1; // 트리1의 루트 노드 설정

    init_BT(&(IBT2.root)); // 트리2 초기화
    IBT2.root = node2; // 트리2의 루트 노드 설정

    set_left(IBT1.root, node3); // 트리1의 루트 노드에 왼쪽 자식으로 노드3 추가
    set_right(IBT1.root, IBT2.root); // 트리1의 루트 노드에 오른쪽 자식으로 트리2의 루트 노드 추가

    init_BT(&(IBT2.root)); // 트리2의 루트 노드를 초기화

    printf("%d\n", get_data(IBT1.root)); // 트리1의 루트 노드의 데이터 출력

    l = get_left(IBT1.root); // 왼쪽 자식 노드
    r = get_right(IBT1.root); // 오른쪽 자식 노드

    printf("%d ", get_data(l)); // 왼쪽 자식 노드의 데이터 출력
    printf("%d\n", get_data(r)); // 오른쪽 자식 노드의 데이터 출력

    if (is_leaf(l)) // 왼쪽 자식이 단말 노드인지 확인
        printf("왼쪽 자식은 단말 노드입니다.\n");

    if (is_leaf(r)) // 오른쪽 자식이 단말 노드인지 확인
        printf("오른쪽 자식은 단말 노드입니다.\n");

    printf("%d\n", get_data(IBT2.root)); // 트리2의 루트 노드의 데이터 출력

    return 0;
}
