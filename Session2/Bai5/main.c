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
    printf("\nNhap vi tri muon xoa: ");
    scanf("%d",&index);
    for (int i = index; i < n; i++)
    {
        arr[i]=arr[i+1];
    }

    for (int i = 0; i < n-1; i++)
    {
        printf("%d",arr[i]);
    }
    
    return 0;
}