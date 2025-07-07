#include <stdio.h>
int count (int n) {
    if (n==0||n==1) {
        return 1;
    }
    return count(n-1)+count(n-2);
}
int main() {
    int n;
    printf("Nhap so bac cau thang: ");
    scanf("%d",&n);
    if (n<0) {
        printf("So bac ko hop le");
        return 1;
    }
    int total = count(n);
    printf("So cach: %d",total);
    return 0;
}