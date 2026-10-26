#include<stdio.h>
# define INFINITY 9999
# define MAX 10
void dijkstras(int g[MAX][MAX],int n,int sn){
    int visited[n],cost[MAX][MAX],distance[n];
    int pred[n],count,i,j,nextnode,mindistance;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(g[i][j]==0)
            cost[i][j]=INFINITY;
            else
            cost[i][j]=g[i][j];
        }
    }
    for(i=0;i<n;i++){
        distance[i]=cost[sn][i];
        pred[i]=sn;
        visited[i]=0;
    }
    visited[sn]=1;
    distance[sn]=0;
    count=1;
    while(count<n){
        mindistance=INFINITY;
        nextnode=-1;
        for(i=0;i<n;i++){
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        if(nextnode==-1)
        break;
        visited[nextnode]=1;
        for(i=0;i<n;i++){
            if(!visited[i]&&mindistance+cost[nextnode][i]<distance[i])
            {
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
        }
        count++;
    }
    for(i=0;i<n;i++){
        if(i!=sn){
            printf("\n distance of %d node is %d\n",i,distance[i]);
            printf("path = %d",i);
            j=i;
            while(j!=sn){
                j=pred[j];
                printf("<-%d",j);
            }
            printf("\n");
        }
    }
}
int main(){
    int n,sn,g[MAX][MAX],i,j;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    printf("enter the starting node:");
    scanf("%d",&sn);
    dijkstras(g,n,sn);
    return 0;
}