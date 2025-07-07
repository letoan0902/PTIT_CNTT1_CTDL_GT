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
    int max =arr[0];
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
            index=i;
        }
    }
    printf("Index = %d\n", index);
    free(arr);
    return 0;
}