#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n){
    int temp, minIndex;
    for (int i = 0; i < n-1; i++)
    {
        minIndex=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            temp = arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
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
    selectionSort(arr, n);
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    free(arr);
    
    return 0;
}