#include <stdio.h>



int demSoDuong(int row, int col){
    if(row==1||col==1){
        return 1;
    }

    return demSoDuong(row-1,col)+demSoDuong(row,col-1);
}
int main(){
    int row;
    int col;

    printf("Nhap row: ");
    scanf("%d", &row);
    printf("Nhap col: ");
    scanf("%d",&col);

    printf("%d",demSoDuong(row, col));
    return 0;
}