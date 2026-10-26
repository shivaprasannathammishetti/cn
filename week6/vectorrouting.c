#include<stdio.h>
struct node{
 unsigned dist[20];
 unsigned from[20];
}rt[10];
int main(){
    int n,i,j,k,count;
    int dmat[10][10];
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=j;
        }
    }
    do{
        count=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j]=dmat[i][k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0);
    for(i=0;i<n;i++){
        printf("state value for router %d is:\n",i+1);
        for(j=0;j<n;j++){
        printf("the node %d via %d distance is %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
    }
    printf("\n");
}
return 0;
}
