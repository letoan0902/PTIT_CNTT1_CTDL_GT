#include <stdio.h>


int inPhanTu(int n, int m, int sum){
    sum+=m;
    if(m>=n){
        return sum;
    }
    inPhanTu(n, m+1, sum);
}


int main() {
    printf("Nhap vao 1 so nguyen duong: ");
    int n;
    scanf("%d",&n);
    if(n<1){
        printf("Khong hop le");
        return 1;
    }
    printf("%d", inPhanTu(n, 0, 0));   
    return 0;
}