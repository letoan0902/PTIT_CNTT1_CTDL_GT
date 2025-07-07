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
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i]=arr[n-i-1];
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",b[i]);
    }
    
    return 0;
}