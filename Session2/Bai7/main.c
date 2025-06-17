#include <stdio.h>

int main(){
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le.\n");
        return 0;
    }

    int arr[100];
    printf("Nhap cac phan tu:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Nhap tong can tim: ");
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < n-1 && !found; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i] + arr[j] == target){
                printf("Cap phan tu la: %d, %d", arr[i], arr[j]);
                found=1;
                break;
            }
        }
        
    }
    
    if(!found){
        printf("Khong tim thay cap nao");
    }
    return 0;
}