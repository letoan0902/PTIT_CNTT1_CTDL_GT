#include <stdio.h>

int dem(int arr[], int a, int n){
    int c=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==a){
            c++;
        }
    }
    return c;
}

int main(){

    int arr[]={1,1,3,4,5,6,6,8,8,2,1,1,8};

    int n=sizeof(arr)/sizeof(arr[0]);
    int a = 8;
    printf("So %d xuat hien %d lan",a,dem(arr,a,n));
    return 0;
}

//Do phuc tap thoi gian: O(n)
//Do phuc tap khong gian O(n)