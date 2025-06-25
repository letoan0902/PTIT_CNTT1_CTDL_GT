#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n<=0){
        printf("So luong phan tu khong hop le");
        return 1;
    }
    int *arr = (int*)calloc(n, sizeof(int));
    printf("Nhap vao tung phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Nhap vao phan tu muon tim: ");
    int a;
    scanf("%d", &a);
    int left =0;
    int right = n-1;

    while(left<=right){
        int mid = (left+right)/2;
        
        if(arr[mid]==a){
            printf("Phan tu co trong mang");
            return 0;
        }else if(arr[mid]<a){
            left=mid+1;
        } else {
            right=mid-1;
        }
    }
    printf("Khong tim thay phan tu\n");
    free(arr);
    return 0;
}