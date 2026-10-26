#include<stdio.h>
int main(){
    int frames[100],i,w,f;
    printf("enter the window size:");
    scanf("%d",&w);
    printf("enter the frame size:");
    scanf("%d",&f);
    printf("enter the frames:");
    for(int i=1;i<=f;i++)
    scanf("%d",&frames[i]);
    printf("with the help of sliding window protocol the frames will be sent tn the following manner");
    printf("after sending %d frames at each stage sender wait for the acknowledgement sent by receiver\n",w);
    for(i=1;i<=f;i++){
        if(i%w==0){
        printf("%d\n",frames[i]);
        printf("acknowledgement of above frames are received\n");
        }
        else
        printf("%d",frames[i]);
    }
    if(f%w!=0)
    printf("Accknowledgement of above frames sent is received by receiver");
    return 0;
}