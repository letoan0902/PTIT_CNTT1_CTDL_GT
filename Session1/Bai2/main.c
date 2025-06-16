#include <stdio.h>

int main(){

    void printDouble(int n){
        int i=0;
        while (i<n){
            printf("%d\n",i);   // Do phuc tap: O(log n)
            i*=2;
        }
    }
    return 0;
}