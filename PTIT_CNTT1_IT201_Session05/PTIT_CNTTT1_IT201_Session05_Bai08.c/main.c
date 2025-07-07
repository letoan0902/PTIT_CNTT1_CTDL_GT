#include <stdio.h>
#include <string.h>
#include <ctype.h>

int chuoiThanhSo(char *str, int index, int value, int *isValid){
    if(str[index]=='\0'){
        return value;
    }

    if(!isdigit(str[index])){
        *isValid=0;
        return 0;
    }

    int digit = str[index] - '0';
    return chuoiThanhSo(str, index+1, value*10+digit, isValid);
}




int main(){

    char input[100];
    printf("Nhap chuoi ky tu: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")]='\0';

    int isNegative =0;
    int start =0;

    if(input[0]=='-'){
        isNegative =1;
        start =1;
    }

    int isValid =1;
    int result = chuoiThanhSo(input, start, 0, &isValid);

    if(!isValid||strlen(input)==0||(isNegative&&strlen(input)==1)){
        printf("Khong hop le");
    } else {
        if(isNegative){
            result=-result;
        }
        printf("Gia tri so nguyen: %d", result);
    }
    return 0;
}