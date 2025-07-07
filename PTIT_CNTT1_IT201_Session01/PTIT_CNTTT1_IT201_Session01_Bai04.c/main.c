#include <stdio.h>

int cach1(int n){
    int sum =0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;  
    }
    return sum;
    //Do phuc tap thoi gian O(n)
    //Do phuc tap khong gian O(1)
}

int cach2(int n){
    int sum =0;
    return sum = (n*(n+1))/2;  
    //Do phuc tap thoi gian O(1)
    //Do phuc tap khong gian  O(1)
}



int main(){
    int n=10;
    printf("Cach 1: %d\nCach2 2: %d", cach1(n),cach2(n));
    return 0;
}

