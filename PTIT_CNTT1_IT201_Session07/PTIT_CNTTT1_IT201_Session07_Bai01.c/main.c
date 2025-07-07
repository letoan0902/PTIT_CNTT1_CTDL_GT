#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
    bubbleSort(arr, n);
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    free(arr);
    
    return 0;
}