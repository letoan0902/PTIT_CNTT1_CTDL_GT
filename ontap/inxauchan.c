#include <stdio.h>
#include <string.h>

int N;
char max[20];
int checkChan(char* str){
    int is1=0;
    for (int i = 0; i < N; i++)
    {
        if(str[i]=='1') is1++;
    }
    if(is1%2==0){
        return 1;
    }else {
        return 0;
    }
}

void inxau(int i){
    for (char c = '0'; c <= '1'; c++)
    {
        max[i]=c;
        if(i==N-1){
            if(checkChan(max)){
                for (int i = 0; i < N; i++)
                {
                    printf("%c ",max[i]);
                }
                printf("\n");
            }
        } else {
            inxau(i+1);
        }
    }
    
}

int main(){
    scanf("%d",&N);
    if(N<2||N>=16){
        return 1;
    }
    inxau(0);
}