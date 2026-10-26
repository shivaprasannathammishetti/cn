#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int packets[5],i,output_rate,bucket_size;
    int packet_time=0,remaining=0;
    srand(time(NULL));
    for(i=0;i<5;i++)
    packets[i]=rand()%10+1;
    printf("enterr the output_rate:");
    scanf("%d\n",&output_rate);
    printf("enter the bucket_size:");
    scanf("%d\n",&bucket_size);
    if(output_rate<=0||bucket_size<=0)
    {
        printf("invalid! value must be positive\n");
        return 0;
    }
    printf("--leaky bucket--\n");
    for(i=0;i<5;i++){
        printf("%d:",packets[i]);
        if(packets[i]>bucket_size)
        printf("the value is exceeded so discarded!");
        else if(remaining+packets[i]>bucket_size)
        printf("the value is exceeded so discarded!");
        else{
            remaining+=packets[i];
            printf("the bytes in bucket is : %d",remaining);
        }
        if(remaining>0){
            int sent=remaining<output_rate?remaining:output_rate;
            remaining-=sent;
            packet_time++;
            printf("time :%d transmitted: %d,remaining:%d",packet_time,sent,remaining);

        }
    }
    while(remaining>0){
        int sent=remaining<output_rate?remaining:output_rate;
            remaining-=sent;
            packet_time++;
            printf("time :%d transmitted: %d,remaining:%d",packet_time,sent,remaining);
    }
    printf("successfull");
    return 0;
}