#include <stdio.h>

#define N 105

char a[N][N];
int n, d[N][N], qx[N*N], qy[N*N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%s", a[i]);
        int sx, sy, ex, ey;
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = -1;

        int front = 0, rear = 0;
        qx[rear] = sx; qy[rear] = sy; rear++;
        d[sx][sy] = 0;

        while (front < rear) {
            int x = qx[front], y = qy[front];
            front++;
            for (int dir = 0; dir < 4; dir++) {
                int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
                for (int nx = x + dx[dir], ny = y + dy[dir];
                     nx >= 0 && ny >= 0 && nx < n && ny < n && a[nx][ny] != 'X';
                     nx += dx[dir], ny += dy[dir]) {
                    if (d[nx][ny] == -1) {
                        d[nx][ny] = d[x][y] + 1;
                        qx[rear] = nx; qy[rear] = ny; rear++;
                    }
                }
            }
        }
        printf("%d\n", d[ex][ey]);
    }
    return 0;
}
