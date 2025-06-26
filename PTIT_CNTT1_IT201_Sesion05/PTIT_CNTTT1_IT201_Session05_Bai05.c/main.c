#include <stdio.h>
#include <string.h>
#include <ctype.h>

void kiemTraDoiXung(char string[50], int left, int right){
    if(left>=right){
        printf("Chuoi doi xung");
         return;
    }
    if(string[left]!=string[right]){
        printf("Chuoi khong doi xung");
        return;
    }
    kiemTraDoiXung(string, left+1, right-1);
}



int main(){
printf("Nhap vao 1 chuoi bat ky: ");
char string[50];
fgets(string, sizeof(string), stdin);
string[strcspn(string, "\n")]='\0';
int len = strlen(string);
kiemTraDoiXung(string, 0, len-1);
    return 0;
}