#include <stdio.h>
char str[20];
int n;
int k;

int checkCap(char* str){
    int cap01=0;
    for (int i = 0; i < n; i++)
    {
        if(str[i]=='0'){
            if(str[i+1]=='1'){
                cap01++;
            }
        }
    }
    if(cap01==k){
        return 1;
    }else {
        return 0;
    }
    
}

void inxau(int i){
    for (int c = '0'; c <= '1'; c++)
    {
        str[i]=c;
        if(i==n-1){
            if(checkCap(str)){
                str[n]='\0';
                printf("%s\n",str);
            }
        }else {
            inxau(i+1);
        }
        
    }
    
}

int main(){
    scanf("%d",&n);
    scanf("%d",&k);
    inxau(0);
    return 0;
}