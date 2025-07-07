#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    free(arr);
    
    return 0;
}