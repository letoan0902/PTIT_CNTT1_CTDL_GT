#include <stdio.h>


void printMatrix(int a[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void sortColumn(int a[][100], int rows, int k) {
    int temp;
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (a[j][k] > a[j + 1][k]) {
                temp = a[j][k];
                a[j][k] = a[j + 1][k];
                a[j + 1][k] = temp;
            }
        }
    }
}

int main() {
    int rows, cols, k;
    int a[100][100];

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("Kich thuoc khong hop le!\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Truoc khi sap xep:\n");
    printMatrix(a, rows, cols);

    printf("Nhap chi so cot can sap xep: ");
    scanf("%d", &k);

    if (k < 0 || k >= cols) {
        printf("Chi so cot khong hop le!\n");
        return 1;
    }
    sortColumn(a-1, rows, k);
    printMatrix(a-1, rows, cols);

    return 0;
}
