#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define FSIZE 3
struct packet{
    int seqNum;
    char data[FSIZE+1];
};
int divide(char msg[],struct packet packets[]){
    int i,j,len,n=0;
    len=strlen(msg);
    for(i=0;i<len;i+=FSIZE){
        packets[n].seqNum=n+1;
        for(j=0;j<FSIZE&&msg[i+j]!='\0';j++)
        packets[n].data[j]=msg[i+j];
        packets[n].data[j]='\0';
        n++;
    }
    return n;
}
void shuffle(struct packet packets[],int n){
    int i,j;
    struct packet temp;
    for(i=n-1;i>0;i--){
        j=rand()%(i+1);
        temp=packets[i];
        packets[i]=packets[j];
        packets[j]=temp;
    }
}
void sort(struct packet packets[],int n){
    int i,j;
    struct packet temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(packets[j].seqNum>packets[j+1].seqNum){
                temp=packets[j];
                packets[j]=packets[j+1];
                packets[j+1]=temp;
            }
        }
    }
}
void receive(struct packet packets[],int n){
    int i,j;
    printf("the packets are received order\n");
    printf("packets before sorting sequnce number is :\n");
    for(i=0;i<n;i++)
    printf("%d",packets[i].seqNum);
    sort(packets,n);
    printf("\n\nthe packets after sorting order is \n");
    for(i=0;i<n;i++)
    printf("%d",packets[i].seqNum);
    printf("the msg order is:");
    for(i=0;i<n;i++)
    printf("%s",packets[i].data);
}
int main(){
    int n;
    char msg[301];
    struct packet packets[100];
    srand(time(NULL));
    printf("enter the msg:");
    fgets(msg,sizeof(msg),stdin);
    msg[strcspn(msg,"\n")]='\0';
    n=divide(msg,packets);
    shuffle(packets,n);
    receive(packets,n);
}
