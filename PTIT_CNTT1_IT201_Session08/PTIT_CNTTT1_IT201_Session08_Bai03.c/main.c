#include<stdio.h>
void sort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("nhap vao so luong phan tu");
    scanf("%d",&n);
    if (n<=0 || n>1000) {
        printf("so luong ko hop le");
        return 1;
    }
    int arr[n];
    for (int i=0; i<n; i++) {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}