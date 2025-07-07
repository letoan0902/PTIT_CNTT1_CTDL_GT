#include <stdio.h>
void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int left, int right, int search)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (search == arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < search)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main(void)
{
    int n, search;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000)
    {
        printf("so luong ko hop le");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    printf("nhap gia tri muon tim kiem: ");
    scanf("%d", &search);

    int result = binarySearch(arr, 0, n - 1, search);
    if (result != -1)
    {
        printf("vi tri thu %d", result + 1);
    }
    else
    {
        printf("ko tim thay phan tu ");
    }
    return 0;
}