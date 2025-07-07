#include <stdio.h>
#define MAX 100

int sumRows(int arr[][MAX], int rows, int cols, int k){
    int sum =0;
    k--;
    for (int i = 0; i < cols; i++)
    {
        sum+=arr[k][i];
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

    int arr[MAX][MAX];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int k;
    printf("k = ");
    scanf("%d", &k);
    if(k<0||k>rows){
        printf("So hang khong hop le");
        return 1;
    }

    printf("sum = %d", sumRows(arr, rows, cols, k));
    return 0;
}