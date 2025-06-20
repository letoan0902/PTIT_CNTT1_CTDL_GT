#include <stdio.h>
#define MAX 100

int sumDiagonal1(int arr[][MAX], int rows){
    int sum =0;
    for (int i = 0; i < rows; i++)
    {
        sum+= arr[i][i];
    }

    return sum;
}

int sumDiagonal2(int arr[][MAX], int rows){
    int sum=0;
    for (int i = 0; i < rows; i++)
    {
        sum+= arr[i][rows-1-i];
    }

    return sum;
}

int main(){
    int rows;
    int cols;
    printf("rows = ");
    scanf("%d",&rows);
    printf("cols = ");
    scanf("%d", &cols);
    if(rows<=0||cols<=0||rows>=1000||cols>=1000){
        printf("Số hàng hoặc số cột không hợp lệ");
        return 1;
    }

    if(rows!=cols){
        printf("Khong phai ma tran vuong");
        return 1;
    }
    int arr[MAX][MAX];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("Tong duong cheo chinh = %d\nTong duong cheo phu=%d", sumDiagonal1(arr, rows), sumDiagonal2(arr, rows));
    return 0;
}