#include <stdio.h>

int main() {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);

    int matrix[100][100];
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}