#include <stdio.h>
#define SIZE 5

typedef struct AG{
    int adj[SIZE][SIZE];
}AG;

//���
void print(AG *G){
    printf("   ");
    for(int i=0;i<SIZE;i++)printf("%d",i);
    for(int i=0;i<SIZE;i++){
        printf("\n%d  ",i);
        for(int j=0;j<SIZE;j++)
            printf("%d",G->adj[i][j]);
    }
    printf("\n\n");
}

//������ ��� �Լ�
void deg(AG *G, int n){
    int i=0,count = 0;
    for (i = 0; i<SIZE;i++){
        count += G->adj[n][i];
    }
    printf("��� %d�� ������: %d�� \n", n+1, count);
}
// ���� ��� ��� �Լ�
void adj_node(AG *G, int n){
    printf("���%d�� ���� ��� : ",n+1);
    for (int i = 0; i<SIZE;i++){
        if(G->adj[n][i]>0) printf("%d  ",i+1);
    }
    printf("\n\n");
}

int main(){
    AG G ={
        .adj={
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
        }
    };

    print(&G);

    for(int i=0;i<SIZE;i++){
        deg(&G, i);
        adj_node(&G, i);
    }
}
