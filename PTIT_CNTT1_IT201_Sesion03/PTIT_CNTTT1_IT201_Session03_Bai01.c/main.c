#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);
    if(n>0){
        printf("So luong phan tu phai lon hon 0");
        return 1;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Cap phat mang that bai\n");
    }
    printf("\nNhap phan tu trong mang: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("\nSo thu %d = %d", i+1,arr[i]);
    }
    
    free(arr);
    return 0;
}