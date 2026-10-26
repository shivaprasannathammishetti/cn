#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char chiper[50],plain[50],key[50];
    int i,ch,lp;
    while(1){
        printf("\n--menu---\n");
        printf("1:data encryption 2:data decryption 3: exit\n");
        printf("enter choice:");
        scanf("%d",&ch);
        getchar();
        switch(ch){
            case 1:
            printf("data encryption\n");
            printf("enter plain text");
            fgets(plain,sizeof(plain),stdin);
            plain[strcspn (plain,"\n")]='\0';
            printf("enter the encryption key");
            fgets(key,sizeof(key),stdin);
            key[strcspn (key,"\n")]='\0';
            lp=strlen(key);
            for(i=0;plain[i]!='\0';i++)
            chiper[i]=plain[i]^lp;
            chiper[i]='\0';
            printf("encryption text is ");
            puts(chiper);
            break;
            case 2:
            printf("data decryption\n");
            for(i=0;chiper[i]!='\0';i++){
                plain[i]=chiper[i]^lp;
            }
            plain[i]='\0';
            printf("the decryption text is");
            puts(plain);
            break;
            case 3:
            exit(0);
            default:
            printf("invalid");
        }
    }
    return 0;
}