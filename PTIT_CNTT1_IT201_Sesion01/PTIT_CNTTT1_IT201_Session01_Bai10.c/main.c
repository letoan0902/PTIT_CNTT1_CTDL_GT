#include <stdio.h>
#include <string.h>

int main(){
    char a[]="hello";
    char b[]="olelho";

    int sum1=0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        sum1 += (int)a[i];
    }
    
    int sum2=0;
    for (int i = 0; b[i] != '\0'; i++)
    {
        sum2 += (int)b[i];
    }

    if(sum1==sum2){
        printf("2 chuoi la hoan vi cua nhau\n");
    } else {
        printf("2 chuoi khong la hoan vi cua nhau\n");
    }

    return 0;
}