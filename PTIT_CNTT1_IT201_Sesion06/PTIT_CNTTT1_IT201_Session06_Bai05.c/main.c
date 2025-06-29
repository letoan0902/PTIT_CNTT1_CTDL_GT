#include<stdio.h>
int findMax(int arr[], int n) {
    if (n==1) return arr[0];
    int max = findMax(arr,n-1);
    if (arr[n-1]>max) {
        return arr[n-1];
    }else {
        return max;
    }
}

int findMin(int arr[],int n) {
    if (n==1) return arr[0];
    int min = findMin(arr,n-1);
    if (arr[n-1] < min) {
        return arr[n-1];
    }else {
        return min;
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);

    if (n<=0) {
        printf("Khong hop le");
        return 1;
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);

    }
    int max = findMax(arr,n);
    int min = findMin(arr,n);
    printf("Phan tu lon nhat la %d \n",max);
    printf("Phan tu nho nhat la %d",min);
    return 0;
}