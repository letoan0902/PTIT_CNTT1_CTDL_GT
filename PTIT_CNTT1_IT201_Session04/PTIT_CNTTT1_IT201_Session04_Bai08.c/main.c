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
    printf("Nhap vao phan tu muon tim: ");
    int a;
    scanf("%d", &a);
    int flag =0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==a){
            printf("%d, ", i);
            flag =1;
        }
    }
    if(flag==0){
        printf("Khong tim thay phan tu\n");
    }
    free(arr);
    return 0;
}