#include <stdio.h>

void swap(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Chuyen dia 1 tu %c qua %c \n", A, C);
        return;
    }
    swap(n-1,A,C,B);
    printf("Chuyen dia %d tu %c sang %c\n",n,A,C);
    swap(n-1,B,A,C);
}

int main() {
    int n;
    printf("Nhap so dia: ");
    scanf("%d",&n);
    if (n<= 0) {
        printf("So nguyen duong");
        return 1;
    }
    swap(n,'A','B','C');
    return 0;
}