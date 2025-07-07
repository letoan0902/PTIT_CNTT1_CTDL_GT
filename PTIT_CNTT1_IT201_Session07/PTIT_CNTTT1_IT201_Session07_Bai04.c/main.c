#include <stdio.h>
#include <ctype.h>
#include <string.h>


void sortString(char str[]){
    int n = strlen(str);
    char temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j =i+1; j < n; j++)
        {
            if(tolower(str[i])>tolower(str[j])){
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
        
    }
    
}

int main(){
    char str[1000];
    printf("Nhap chuoi bat ky: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    sortString(str);
    printf("Chuoi: %s",str);
    return 0;
}