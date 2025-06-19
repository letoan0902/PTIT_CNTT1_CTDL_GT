#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if(n<=0){
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int *arr = (int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int *result = (int*)malloc(n*sizeof(int));
    int count =0;

    int maxRight = arr[n-1];
    result[count++]=maxRight;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxRight){
            maxRight=arr[i];
            result[count++]=arr[i];
        }
    }

    printf("Cac phan tu thoa man: ");
    for (int i = count-1; i >=0; i--){
        printf("%d ", result[i]);
    }
    free(arr);
    free(result);
    
    return 0;
}