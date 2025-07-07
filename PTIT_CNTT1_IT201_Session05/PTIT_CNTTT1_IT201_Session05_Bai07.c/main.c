#include <stdio.h>
#include <stdlib.h>

void fibonaci(int arr[], int n, int m){
    if(n==m){
        for (int i = 0; i < n; i++)
        {
            printf("%d, ",arr[i]);
        }
        return;
    }
    int f0=0;
    int f1=0;
    if(m==0){
       f0=0; 
    } else if(m==1) {
        f1=1;
    }else {
        f0=arr[m-2];
        f1=arr[m-1];
    }
    arr[m]=f0+f1;
    fibonaci(arr, n, m+1);
}



int main(){

    printf("Nhap so: ");
    int n;
    scanf("%d", &n);
    if(n<=0){
        printf("Khong hop le");
        return 1;
    }
    int *arr = (int*)calloc(n, sizeof(int));
    fibonaci(arr, n, 0);

    free(arr);
    return 0;
}