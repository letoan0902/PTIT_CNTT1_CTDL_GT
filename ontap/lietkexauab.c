#include <stdio.h>
#include <string.h>

int N;
char max[20];
int checkAB(char* str){
    int isA=0;
    int isB=0;
    for (int i = 0; i < N; i++)
    {
        if(max[i]=='A'){
            isA++;
        }
        if(max[i]=='B') isB++;
    }
    if(isA==0||isB==0){
        return 0;
    }else {
        return 1;
    }
}

void inxau(int i){
    for (char c = 'A'; c <= 'B'; c++)
    {
        max[i]=c;
        if(i==N-1){
            if(checkAB(max)){
                max[i+1]='\0';
                printf("%s\n",max);
            }
        } else {
            inxau(i+1);
        }
    }
    
}

int main(){
    scanf("%d",&N);
    if(N<2||N>=15){
        return 1;
    }
    inxau(0);
}