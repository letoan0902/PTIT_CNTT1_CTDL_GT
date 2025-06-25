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
    int flag =0;
    for (int i = 0; i < n/2; i++)
    {
        if(arr[i]==arr[n-1-i]){
            printf("Cap doi xung: (%d,%d)\n", arr[i], arr[n-i-1]);
            flag =1;
        }
    }
    if(flag==0){
        printf("Khong co phan tu doi xung");
    }
    free(arr);

    return 0;
}