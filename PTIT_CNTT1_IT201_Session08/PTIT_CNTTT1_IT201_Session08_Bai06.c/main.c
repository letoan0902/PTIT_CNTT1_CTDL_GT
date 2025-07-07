#include<stdio.h>

void merge(int arr[], int l, int mid, int r) {
    int i, j, k;
    int leftArrSize = mid - l +1;
    int rightArrSize = r - mid;
    int leftArr[leftArrSize] , rightArr[rightArrSize];
    for (int i= 0; i < leftArrSize; i++) {
        leftArr[i] =arr[l+i];
    }
    for (int i=0; i<rightArrSize; i++) {
        rightArr[i] = arr[mid+1+i];
    }
    i = 0, j = 0, k =l;
    while (i < leftArrSize && j <rightArrSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < leftArrSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightArrSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l, int r) {
    if (l == r) return;
    int mid = (l + r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l , mid, r);
}

int main() {
    int n;
    printf("nhap so luong phan tu: ");
    scanf("%d",&n);
    if (n<=0) {
        printf("so luong ko hop le");
        return 1;
    }
    int arr[n];
    for (int i = 0; i <n; i++) {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("mang sau khi duoc sap xep \n");
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}