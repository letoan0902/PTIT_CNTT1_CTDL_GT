#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Students {
    int id;
    char name[50];
    int age;
};

int main(){
    int n;
    printf("Nhap so luong sinh vien");
    scanf("%d",&n);
    struct Students* ds = (struct Students*) calloc(n,sizeof(struct Students));

    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d: \n", i+1);

        printf("Id: ");
        scanf("%d", &ds[i].id);
        getchar();

        printf("Ten: ");
        fgets(ds[i].name, sizeof(ds[i].name), stdin);
        ds[i].name[strcspn(ds[i].name, "\n")]='\0';
        printf("Tuoi: ");
        scanf("%d", &ds[i].age);
    }
    int a;
    printf("Nhap id muon tim: ");
    scanf("%d", &a);
    for (int i = 0; i < n; i++)
    {
        if(ds[i].id==a){
            printf("Id: %d, name: %s, age: %d", ds[i].id, ds[i].name, ds[i].age);
            return 0;
        }
    }
    printf("Sinh vien khong ton tai");

    free(ds);
    return 0;
}