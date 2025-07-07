#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a=*b;
    *b=temp;
}
int selectPivot(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    for (int j=l; j < r; j++) {
        if (arr[j] <pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int pivot = selectPivot(arr,l,r);
    quickSort(arr,l,pivot-1); // sx trai
    quickSort(arr,pivot+1,r); // sx phai
}
int main() {
    int n;
    printf("nhap so luong phan tu: ");
    scanf("%d",&n);
    if (n<=0 || n>1000) {
        printf("so luong ko hop le");
        return 1;
    }
    int arr[n];
    for (int i = 0; i< n; i++) {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("mang sau khi duoc sap xep\n");
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}