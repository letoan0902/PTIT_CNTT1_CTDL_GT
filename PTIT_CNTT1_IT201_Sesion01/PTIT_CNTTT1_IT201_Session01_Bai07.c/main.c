#include <stdio.h>
#include <stdlib.h>

char* cach1(int arr[], int n){

    int flag =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j]){
                flag=1;
            }
        }
        
    }
    if(flag==1){
        return "Co phan tu trung lap";
    } else {
        return "Khong co phan tu trung lap";
    }

}

char* cach2(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int* a = (int*)calloc(max + 1, sizeof(int));
    

    for (int i = 0; i < n; i++)
    {
        if(a[i]==1){
            return "Co phan tu trung lap";
        } else {
            a[arr[i]]=1;
        }
    }

    free(a);

     return "Khong co phan tu trung lap";
    
}


int main(){

int arr[]={1,2,5,46,7,9,3,5};
int n = sizeof(arr)/sizeof(arr[0]);

printf("Cach 1: %s\n",cach1(arr,n));
//Do phuc tap thoi gian O(n^2)
//Do phuc tap khong gianO(n)

printf("Cach 2: %s",cach2(arr,n));
//Do phuc tap thoi gian O(n);
//Do phuc tap khong gian O(n)+O(max)

    return 0;
}