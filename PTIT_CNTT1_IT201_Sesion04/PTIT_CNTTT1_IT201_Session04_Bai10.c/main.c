#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Students {
    int id;
    char name[50];
    int age;
};

char* upperString(char *str){
    int len = strlen(str);

    char* result = (char*)calloc(len+1, sizeof(char));
    for (int i = 0; i < len; i++)
    {
        result[i]=toupper(str[i]);
    }
    result[len]='\0';
    return result;
}

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
    char a[50];
    int flag=0;
    getchar();
    printf("Nhap chuoi muon tim: ");
    fgets(a,sizeof(a), stdin);
    a[strcspn(a, "\n")]='\0';
    for (int i = 0; i < n; i++)
    {
        if(strstr(upperString(ds[i].name), upperString(a))!=NULL){
            printf("Id: %d, name: %s, age: %d\n", ds[i].id, ds[i].name, ds[i].age);
            flag =1;
        }
    }
    if(flag==0){
    printf("Sinh vien khong ton tai");
    }
    free(ds);
    return 0;
}