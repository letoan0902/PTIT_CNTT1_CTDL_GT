#include <stdio.h>


int inPhanTu(int n, int m, int sum){
    sum+=m;
    if(m>=n){
        return sum;
    }
    inPhanTu(n, m+1, sum);
}


int main() {
    printf("Nhap vao so A nguyen duong: ");
    int a;
    scanf("%d",&a);
    int b;
    printf("Nhap vao so B nguyen duong: ");
    scanf("%d",&b);
    if(a<0||b<0){
        printf("Khong hop le");
        return 1;
    }
    if(a<b){
        int temp = a;
        a=b;
        b=temp;
    }
    printf("%d", inPhanTu(a, b, 0));   
    return 0;
}