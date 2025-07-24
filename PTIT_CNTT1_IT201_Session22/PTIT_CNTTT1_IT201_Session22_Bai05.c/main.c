#include <stdio.h>

int main() {
    int n, v;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    int edges[100][2];

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int count = 0;
    for (int i = 0; i < v; i++) {
        if (edges[i][0] == k || edges[i][1] == k) {
            count++;
        }
    }

    printf("So dinh ke voi %d la: %d\n", k, count);

    return 0;
}