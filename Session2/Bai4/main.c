#include <stdio.h>

int main(){
    printf("Nhap so luong phan tu: ");
    int n;
    scanf("%d",&n);
    if(n<=0||n>=100){
        printf("So luong nam trong khoang 1-100");
        return 0;
    }
    int arr[n];
    printf("\nNhap tung phan tu trong mang: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int index;
    printf("\nNhap vi tri muon sua: ");
    scanf("%d",&index);
    int giatri;
    printf("\nNhap gia tri: ");
    scanf("%d",&giatri);
    arr[index]=giatri;
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}