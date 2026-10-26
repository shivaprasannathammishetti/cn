#include<stdio.h>
#define MAX 10
int adjacent[MAX][MAX];
int numnode;
void adjacentNodes(int rn){
    for(int i=0;i<numnode;i++){
        if(adjacent[i][rn]==1||adjacent[rn][i]==1)
        printf("%d",i);
    }
    printf("\n");
}
int main(){
    int root;
    printf("enter the number of nodes:");
    scanf("%d",&numnode);
    printf("enter adjacent matrix:");
    for(int i=0;i<numnode;i++){
        for(int j=0;j<numnode;j++){
            scanf("%d",&adjacent[i][j]);
        }
    }
    printf("enter the root node");
    scanf("%d",&root);
    adjacentNodes(root);
    return 0;
}
