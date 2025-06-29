#include<stdio.h>

int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return (n%10)+ sum(n/10);
}
int main() {
    int n;
    printf("Nhap so ");
    scanf("%d",&n);
    if (n<=0) {
        printf("Khong hop le");
        return 1;
    }
    int tong = sum(n);
    printf("Tong cac chu so trong %d la %d",n,tong);
    return 0;
}