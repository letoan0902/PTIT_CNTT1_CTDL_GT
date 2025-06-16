#include <stdio.h>

int main(){
    int* mallocArray(int n){
        int* arr = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++){
            arr[i] =i;   //Do phuc tap O(n)
        }
        return arr;
    }
    return 0;
}