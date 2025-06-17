#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("So luong nam trong khoang 1-100\n");
        return 0;
    }

    int* arr = (int*) malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return 1;
    }

    printf("\nNhap tung phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int index, giatri;
    printf("\nNhap vi tri muon them: ");
    scanf("%d", &index);

    if (index < 0 || index > n) {
        printf("Vi tri chen khong hop le!\n");
        free(arr);
        return 0;
    }

    printf("Nhap gia tri: ");
    scanf("%d", &giatri);

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = giatri;
    n++;

    printf("\nMang sau khi chen:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
