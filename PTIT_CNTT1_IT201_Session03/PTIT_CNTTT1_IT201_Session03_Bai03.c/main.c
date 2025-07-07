#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);
    if(n<=0){
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
    
    int quantity = 0;
    int sum=0;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]%2==0){
            sum+=arr[i];
            quantity++;
        }
    }
    
    printf("\naverage = %d", sum/quantity);


    free(arr);
    return 0;
}