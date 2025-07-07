#include <stdio.h>



int demSoDuong(int row, int col, int n, int m, int i, int j){
    if(i>=row||j>=col){
        return 0;
    }
    if(i==n&&j==m){
        return 0;
    }
    if(i==row-1&&j==col-1){
        return 1;
    }
    
    return demSoDuong(row,col, n, m, i+1,j)+demSoDuong(row,col, n, m, i, j+1);
}
int main(){
    int row;
    int col;

    printf("Nhap row: ");
    scanf("%d", &row);
    printf("Nhap col: ");
    scanf("%d",&col);
    int n;
    int m;
    printf("Nhap row chan: ");
    scanf("%d", &n);
    printf("Nhap col chan: ");
    scanf("%d",&m);
    printf("%d",demSoDuong(row, col, n, m, 0, 0));
    return 0;
}