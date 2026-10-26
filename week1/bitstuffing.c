#include<stdio.h>
int main(){
    int a[100],b[100],i,j=0,count=0,n;
    printf("enter the frame length:\n");
    scanf("%d",&n);
    if(n<1||n>100){
        printf("invalid length....");
        return 1;
    }
    printf("enter the frame with 0's and 1's:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        b[j++]=a[i];
        if(a[i]==1)
        count++;
        else
        count=0;
        if(count==5){
        b[j++]=0;
        count=0;
        }
    }
    printf("the message received by receiver isss:");
    for(i=0;i<j;i++){
        printf("%d",b[i]);
    }
    return 0;
}
