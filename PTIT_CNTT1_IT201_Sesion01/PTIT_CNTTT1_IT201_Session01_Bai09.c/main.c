#include <stdio.h>



void inmatran(int a[3][3],int m, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    
}

void induongcheochinh(int a[3][3],int size){
    for (int i = 0; i < size; i++){
        printf("%d ,",a[i][i]);
    }
    
}


int main(){

    int a[3][3] ={{1,2,3},{4,5,6},{7,8,9}};

    inmatran(a, 3, 3);
    //Do phuc tap thoi gian: O(n*m)
    //Do phuc tap khong gian: O(1)

    induongcheochinh(a,3);
    //Do phuc tap thoi gian: O(n)
    //Do phuc tâp khong gian O(1)
    return 0;
}