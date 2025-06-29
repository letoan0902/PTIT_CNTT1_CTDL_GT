#include <stdio.h>

int fibonacci(int index) {
    if ( index == 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }
    return fibonacci(index-1) +fibonacci(index-2);
}
int main() {
    int n;
    printf("Nhap so ");
    scanf("%d",&n);
    if (n<=0) {
        printf("so ko hop le");
        return 1;
    }
    int arr[n];
    for (int i=0;i<n;i++) {
        arr[i] = fibonacci(i);
    }
    for (int i = n-1; i>=0; i--) {
        printf("%d ",arr[i]);
    }
    return 0;
}