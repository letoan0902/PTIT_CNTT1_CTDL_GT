#include <stdio.h>


void binary(int n){
    if(n==0){
        return;
    }
    binary(n/2);
    printf("%d",n%2);
}


int main() {
    int n;
    printf("Nhap so: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Khong hop le");
        return 1;
    }
    binary(n);
    
    return 0;
}