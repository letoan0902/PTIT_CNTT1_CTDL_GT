#include <stdio.h>
#include <stdlib.h>


int main(){

    int arr[]={1,4,3,6,5,8,6,4,4,4,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int* a = (int*)calloc(max + 1, sizeof(int));
    int m = max+1;
    
     for (int i = 0; i < n; i++)
    {
            a[arr[i]]++;
    }

    max = a[0];
    int index=0;
    for (int i = 1; i < m; i++)
    {
        if(a[i]>max){
            max=a[i];
            index=i;
        }
    }
    printf("Phan tu %d xuat hien nhieu nhat: %d lan\n",index,max);

    free(a);
    return 0;
}


//Do phuc tap thoi gian: O(n+max)
//Do phuc tap khong gian O(max)