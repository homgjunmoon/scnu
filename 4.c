#include <stdio.h>
#define SIZE 5

typedef struct AG{
    int adj[SIZE][SIZE];
}AG;

//출력
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

//분지수 출력 함수
void deg(AG *G, int n){
    int i=0,count = 0;
    for (i = 0; i<SIZE;i++){
        count += G->adj[n][i];
    }
    printf("노드 %d의 분지수: %d개 \n", n+1, count);
}
// 인접 노드 출력 함수
void adj_node(AG *G, int n){
    printf("노드%d의 인접 노드 : ",n+1);
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
