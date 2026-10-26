#include<stdio.h>
int data[100],gen[100],temp[200],i,c,dl,gl,total;
void xor_op(){
    for(i=0;i<gl;i++)
    temp[i]=temp[i]^gen[i];
}
void left_shift(){
    for(i=0;i<gl-1;i++)
    temp[i]=temp[i+1];
    if(c<total)
    temp[gl-1]=data[c];
    else
    temp[gl-1]=0;
}
int main(){
    int choice,original,error=0;
    printf("1 generate crc  2: check crc\n");
    printf("enter choice");
    scanf("%d",&choice);
    printf("enter the data length:");
    scanf("%d",&dl);
    printf("enter the data bits(0 or 1 bit):\n");
    for(i=0;i<dl;i++)
    {
        scanf("%d",data[i]);
    }
    printf("enter the generator length:");
    scanf("%d",&gl);
    printf("enter the generator bits(start and end must be 1):\n");
    for(i=0;i<gl;i++)
    scanf("%d",gen[i]);
    original=dl;
    total=dl;
    if(choice==1){
        for(i=dl;i<dl+gl-1;i++)
        data[i]=0;
        total=dl+gl-1;
    }
    for(i=0;i<gl;i++)
    temp[i]=data[i];
    for(c=gl;c<total;c++){
        if(temp[0]==1)
        xor_op();
        left_shift();
    }
    if(temp[0]==1)
    xor_op();
    printf("crc remainder:");
    for(i=1;i<gl;i++){
    printf("%d",temp[i]);
    if(temp[i]!=0)
    error=1;
    }
    if(choice==1){
        printf("tramsmitted codework:");
        for(i=0;i<total;i++)
        printf("%d",data[i]);
        for(i=1;i<gl;i++)
        printf("%d",temp[i]);
    }
    else{
        if(error)
        printf("error detected");
        else
        printf("no error detected");
    }
    return 0;
}