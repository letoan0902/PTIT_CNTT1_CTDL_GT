#include <stdio.h>
#include <stdlib.h>

int tinhTong(int arr[], int n, int sum, int index){
    if(index==n){
        return sum;
    }
    sum+=arr[index];
    tinhTong(arr, n, sum, index+1);
}


int main(){

    printf("Nhap vao so luong mang: ");
    int n;
    scanf("%d",&n);
    int *arr = (int*)calloc(n, sizeof(int));
    printf("Nhap vao cac phan tu trong mang: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("%d",tinhTong(arr, n, 0, 0));


    free(arr);
    return 0;
}