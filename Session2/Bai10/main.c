#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if(n<=0){
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int *arr = (int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int* a = (int*)calloc(max + 1, sizeof(int));
    int m = max+1;
    
    int *first = (int*)malloc((max+1)*sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        first[i]=-1;
    }
    


     for (int i = 0; i < n; i++)
    {
            a[arr[i]]++;
            if(first[arr[i]]==-1){
                first[arr[i]]=i;
            }
    }

    max = a[0];
    int index=0;
    for (int i = 1; i < m; i++)
    {
        if(a[i]>max||(a[i]==max&&first[i]<first[index])){
            max=a[i];
            index=i;
        }
    }
    for (int i = 0; i < n; i++) {
    int val = arr[i];
    if (first[val] == i) {
        printf("Phan tu %d xuat hien %d lan\n", val, a[val]);
    }
}

    free(a);
    free(first);
    return 0;
}