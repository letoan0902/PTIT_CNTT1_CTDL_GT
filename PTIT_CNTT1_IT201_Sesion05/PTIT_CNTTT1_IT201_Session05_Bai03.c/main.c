#include <stdio.h>


int tinhGiaiThua(int n, int m, int sum){
    sum*=m;
    if(m>=n){
        return sum;
    }
    tinhGiaiThua(n, m+1, sum);
}


int main() {
    printf("Nhap vao 1 so nguyen duong: ");
    int n;
    scanf("%d",&n);
    if(n<1){
        printf("Khong hop le");
        return 1;
    }
    printf("%d", tinhGiaiThua(n, 1,1));   
    return 0;
}