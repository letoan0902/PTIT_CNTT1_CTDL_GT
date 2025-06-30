#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n){
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key =arr[i];
        j=i-1;
        while (j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}



int main() {

    int n, i;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if(n<=0||n>1000){
        printf("So luong khong hop le");
        return 1;
    }
    int *arr = (int*)calloc(n, sizeof(int));
    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Mang truoc khi xap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    insertionSort(arr, n);
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    free(arr);
    
    return 0;
}