#include <stdio.h>
#define MAX 100

int findMax(int arr[][MAX], int rows, int cols){
    int max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(arr[i][j]>max){
                max=arr[i][j];
            }
        }
    }

    return max;
}

int findMin(int arr[][MAX], int rows, int cols){
    int min = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(arr[i][j]<min){
                min=arr[i][j];
            }
        }
    }

    return min;
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
    
    printf("max = %d\nmin=%d", findMax(arr, rows, cols), findMin(arr, rows, cols));
    return 0;
}