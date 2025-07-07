#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n - 1);
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    free(arr);
    
    return 0;
}