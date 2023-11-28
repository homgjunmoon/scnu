#include <stdio.h>
#include <stdlib.h>
#define DataType int //�ñ��� 1. typedef int DataType�� ������..?

//���� Ʈ�� ��� ���� ����
typedef struct Tnode {
    struct Tnode *left; //���� �ڽ� ��带 ����Ű�� ������
    DataType data; //����� ������
    struct Tnode *right; //������ �ڽ� ��带 ����Ű�� ������
} Tnode;

typedef struct LinkedBT {
    Tnode *root; // ��Ʈ ��带 ����Ű�� ������
} LinkedBT;

//Ʈ�� �ʱ�ȭ
void init_BT(Tnode **root) {
    *root = NULL; //��带 NULL�� �ʱ�ȭ
}
// Ʈ�� �׸� ��� �Լ�
void print_BT(Tnode *root) {
    // Ʈ���� ��ȸ�ϸ� �׸� ���
}
//���� �ڽ� ��� ���� �Լ�
// child�� ��� root�� ���� ����Ʈ���� ����
void set_left(Tnode *root, Tnode *child) {
    if (root->left) {//���� ����Ʈ���� �̹� �����ϴ� ���
        printf("���� ����Ʈ���� �̹� �����մϴ�.\n");
        exit(1);
    }
    else {
        root->left = child;//���� �ڽ� ��带 ����
    }
}
//���� �ڽ� ��� ���� �Լ�
// child�� ��� root�� ������ ����Ʈ���� ����
void set_right(Tnode *root, Tnode *child) {//������ ����Ʈ���� �̹� �����ϴ� ���
    if (root->right) {
        printf("������ ����Ʈ���� �̹� �����մϴ�.\n");
        exit(1);
    }
    else {
        root->right = child;//������ �ڽ� ��带 ����
    }
}
// �ܸ� ��� �Ǵ� �Լ�
int is_leaf(Tnode *node) {
    //����, ������ �ڽ� ��尡 ��� ������ �ܸ� ���
    return !node->left && !node->right;
}
// ��� ������ ��ȯ
DataType get_data(Tnode *node) {
    if (!node) {
        printf("�� ����̹Ƿ� �����͸� ��ȯ�� �� �����ϴ�.\n");
        exit(1);
    }
    else {
        return node->data;//����� ������ ��ȯ
    }
}
//����� �θ� ��� ��ȯ
Tnode *get_parent(Tnode *root) {
// �θ� ��带 ����Ű�� �ʵ带 �߰��Ͽ� ����
}

//����� ���� �ڽ� ��带 ��ȯ
Tnode *get_left(Tnode *node) {
    return node->left;//����� ���� �ڽ� ��� ��ȯ
}

//����� ������ �ڽ� ��� ��ȯ
Tnode *get_right(Tnode *node) {
    return node->right;//����� ������ �ڽ� ��� ��ȯ
}

int main() {
    LinkedBT IBT1, IBT2;
    Tnode *node1 = (Tnode *)malloc(sizeof(Tnode));//��� ���� �Ҵ�
    Tnode *node2 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *node3 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *l, *r;//����, ������ �ڽ� ��带 ����Ű�� ������ ����
    //���1�� ������ ���� �� �ڽ� ��� NULL �ʱ�ȭ
    node1->data = 10; node1->left = node1->right = NULL;
     //���2�� ������ ���� �� �ڽ� ��� NULL �ʱ�ȭ
    node2->data = 20; node2->left = node2->right = NULL;
     //���3�� ������ ���� �� �ڽ� ��� NULL �ʱ�ȭ
    node3->data = 30; node3->left = node3->right = NULL;

    init_BT(&(IBT1.root)); // Ʈ��1 �ʱ�ȭ
    IBT1.root = node1; // Ʈ��1�� ��Ʈ ��� ����

    init_BT(&(IBT2.root)); // Ʈ��2 �ʱ�ȭ
    IBT2.root = node2; // Ʈ��2�� ��Ʈ ��� ����

    set_left(IBT1.root, node3); // Ʈ��1�� ��Ʈ ��忡 ���� �ڽ����� ���3 �߰�
    set_right(IBT1.root, IBT2.root); // Ʈ��1�� ��Ʈ ��忡 ������ �ڽ����� Ʈ��2�� ��Ʈ ��� �߰�

    init_BT(&(IBT2.root)); // Ʈ��2�� ��Ʈ ��带 �ʱ�ȭ

    printf("%d\n", get_data(IBT1.root)); // Ʈ��1�� ��Ʈ ����� ������ ���

    l = get_left(IBT1.root); // ���� �ڽ� ���
    r = get_right(IBT1.root); // ������ �ڽ� ���

    printf("%d ", get_data(l)); // ���� �ڽ� ����� ������ ���
    printf("%d\n", get_data(r)); // ������ �ڽ� ����� ������ ���

    if (is_leaf(l)) // ���� �ڽ��� �ܸ� ������� Ȯ��
        printf("���� �ڽ��� �ܸ� ����Դϴ�.\n");

    if (is_leaf(r)) // ������ �ڽ��� �ܸ� ������� Ȯ��
        printf("������ �ڽ��� �ܸ� ����Դϴ�.\n");

    printf("%d\n", get_data(IBT2.root)); // Ʈ��2�� ��Ʈ ����� ������ ���

    return 0;
}
