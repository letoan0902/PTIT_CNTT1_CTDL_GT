#include <stdio.h>

int main(void) {
    int n,search;
    int index = 0;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&n);
    if (n<=0||n>1000) {
        printf("so luong ko hop le");
        return 1;
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    printf("nhap gia tri muon tim kiem: ");
    scanf("%d",&search);
    for (int i=0; i<n; i++) {
        if (arr[i]==search) {
            index = i+1;
            break;
        }
    }
    if (index!=0) {
        printf("vi tri so %d",index);
    }else {
        printf("ko ton tai phan tu");
    }

    return 0;
}