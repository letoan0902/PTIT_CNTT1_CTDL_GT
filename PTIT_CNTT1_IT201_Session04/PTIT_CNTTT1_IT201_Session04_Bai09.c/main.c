#include <stdio.h>
#include <stdlib.h>


int nhiPhan(int arr[], int left, int right, int target){
    if(left>right){
        return -1;
    }

    int mid = (left + right) / 2;
    if(arr[mid]==target){
        return mid;
    } else if(arr[mid>target]){
        return nhiPhan(arr, left, mid-1, target);
    } else {
        return nhiPhan(arr, mid +1, right, target);
    }
}

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
    int index = nhiPhan(arr, left, right, a);
    if(index!=-1){
        printf("Phan tu co trong mang");
    } else {
    printf("Khong tim thay phan tu\n");
    }
    free(arr);
    return 0;
}