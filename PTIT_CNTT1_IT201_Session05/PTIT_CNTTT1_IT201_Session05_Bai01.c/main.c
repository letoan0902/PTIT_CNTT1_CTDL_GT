#include <stdio.h>


void inPhanTu(int n, int m){
    printf("%d",m);
    if(m>=n){
        return;
    }
    inPhanTu(n, m+1);
}


int main() {
    printf("Nhap vao 1 so nguyen duong: ");
    int n;
    scanf("%d",&n);
    inPhanTu(n, 1);
    
    return 0;
}