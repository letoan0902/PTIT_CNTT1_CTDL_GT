#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, x;

    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    int arr[1000];

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Mang sau khi sap xep (Insertion Sort): ");
    printArray(arr, n);

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int idxLinear = linearSearch(arr, n, x);
    if (idxLinear != -1)
        printf("Tuyen tinh: %d tai vi tri %d.\n", x, idxLinear);
    else
        printf("Tuyen tinh: Khong tim thay %d.\n", x);

    int idxBinary = binarySearch(arr, n, x);
    if (idxBinary != -1)
        printf("Nhi phan: %d tai vi tri %d.\n", x, idxBinary);
    else
        printf("Nhi phan: Khong tim thay %d.\n", x);

    return 0;
}
