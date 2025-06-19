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
    int a;
    int b=0;
    printf("\nNhap so can dem: ");
    scanf("%d",&a);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==a){
            b++;
        }
    }
    printf("\nSo %d xuat hien: %d lan",a,b);

    return 0;
}