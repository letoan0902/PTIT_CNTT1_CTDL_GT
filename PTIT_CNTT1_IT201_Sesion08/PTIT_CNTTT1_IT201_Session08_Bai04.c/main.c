#include<stdio.h>
void sort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int index = i;
        for (int j= i+1; j<n; j++) {
            if (arr[index] > arr[j]) {
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
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