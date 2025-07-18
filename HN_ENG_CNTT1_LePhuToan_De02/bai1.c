#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Activity
{
    int id;
    char type[50];
    int duration;
    int calories;
    char date[20];
    struct Activity *next;
} Activity;

Activity *head = NULL;
int nextId = 1;

void addActivity()
{
    Activity *newActivity = (Activity *)malloc(sizeof(Activity));
    newActivity->id = nextId++;

    printf("Nhap loai hoat dong: ");
    fflush(stdin);
    fgets(newActivity->type, sizeof(newActivity->type), stdin);
    newActivity->type[strcspn(newActivity->type, "\n")] = 0;

    printf("Nhap thoi gian thuc hien (phut): ");
    scanf("%d", &newActivity->duration);

    printf("Nhap so calories tieu thu: ");
    scanf("%d", &newActivity->calories);

    printf("Nhap ngay thuc hien (dd/mm/yyyy): ");
    fflush(stdin);
    fgets(newActivity->date, sizeof(newActivity->date), stdin);
    newActivity->date[strcspn(newActivity->date, "\n")] = 0;

    newActivity->next = head;
    head = newActivity;

    printf("Da them hoat dong thanh cong! ID: %d\n", newActivity->id);
}

void displayActivities()
{
    if (head == NULL)
    {
        printf("Danh sach hoat dong trong!\n");
        return;
    }

    printf("\n--- DANH SACH HOAT DONG ---\n");
    printf("%-5s %-20s %-10s %-10s %-15s\n", "ID", "Loai", "Thoi gian", "Calories", "Ngay");
    printf("-------------------------------------------------------------\n");

    Activity *current = head;
    while (current != NULL)
    {
        printf("%-5d %-20s %-10d %-10d %-15s\n",
               current->id, current->type, current->duration,
               current->calories, current->date);
        current = current->next;
    }
    printf("\n");
}

void deleteActivity()
{
    if (head == NULL)
    {
        printf("Danh sach hoat dong trong!\n");
        return;
    }

    int id;
    printf("Nhap ID hoat dong can xoa: ");
    scanf("%d", &id);

    if (head->id == id)
    {
        Activity *temp = head;
        head = head->next;
        free(temp);
        printf("Da xoa hoat dong ID %d thanh cong!\n", id);
        return;
    }

    Activity *current = head;
    while (current->next != NULL && current->next->id != id)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Khong tim thay hoat dong voi ID %d!\n", id);
    }
    else
    {
        Activity *temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("Da xoa hoat dong ID %d thanh cong!\n", id);
    }
}

void updateActivity()
{
    if (head == NULL)
    {
        printf("Danh sach hoat dong trong!\n");
        return;
    }

    int id;
    printf("Nhap ID hoat dong can cap nhat: ");
    scanf("%d", &id);

    Activity *current = head;
    while (current != NULL && current->id != id)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Khong tim thay hoat dong voi ID %d!\n", id);
        return;
    }

    printf("Thong tin hien tai:\n");
    printf("Loai: %s, Thoi gian: %d phut, Calories: %d, Ngay: %s\n",
           current->type, current->duration, current->calories, current->date);

    printf("Nhap loai hoat dong moi: ");
    fflush(stdin);
    fgets(current->type, sizeof(current->type), stdin);
    current->type[strcspn(current->type, "\n")] = 0;

    printf("Nhap thoi gian thuc hien moi (phut): ");
    scanf("%d", &current->duration);

    printf("Nhap so calories tieu thu moi: ");
    scanf("%d", &current->calories);

    printf("Nhap ngay thuc hien moi (dd/mm/yyyy): ");
    fflush(stdin);
    fgets(current->date, sizeof(current->date), stdin);
    current->date[strcspn(current->date, "\n")] = 0;

    printf("Da cap nhat hoat dong ID %d thanh cong!\n", id);
}

void calculateCaloriesByDate()
{
    if (head == NULL)
    {
        printf("Danh sach hoat dong trong!\n");
        return;
    }

    char searchDate[20];
    printf("Nhap ngay can thong ke (dd/mm/yyyy): ");
    fflush(stdin);
    fgets(searchDate, sizeof(searchDate), stdin);
    searchDate[strcspn(searchDate, "\n")] = 0;

    int totalCalories = 0;
    int count = 0;
    Activity *current = head;

    while (current != NULL)
    {
        if (strcmp(current->date, searchDate) == 0)
        {
            totalCalories += current->calories;
            count++;
        }
        current = current->next;
    }

    if (count == 0)
    {
        printf("Khong co hoat dong nao trong ngay %s!\n", searchDate);
    }
    else
    {
        printf("Tong calories tieu thu trong ngay %s: %d calories (%d hoat dong)\n",
               searchDate, totalCalories, count);
    }
}

void sortByCalories()
{
    if (head == NULL || head->next == NULL)
    {
        printf("Danh sach khong du du lieu de sap xep!\n");
        return;
    }

    Activity *current = head;
    while (current != NULL)
    {
        Activity *minNode = current;
        Activity *temp = current->next;

        while (temp != NULL)
        {
            if (temp->calories < minNode->calories)
            {
                minNode = temp;
            }
            temp = temp->next;
        }

        if (minNode != current)
        {
            int tempId = current->id;
            char tempType[50], tempDate[20];
            int tempDuration = current->duration;
            int tempCalories = current->calories;

            strcpy(tempType, current->type);
            strcpy(tempDate, current->date);

            current->id = minNode->id;
            strcpy(current->type, minNode->type);
            current->duration = minNode->duration;
            current->calories = minNode->calories;
            strcpy(current->date, minNode->date);

            minNode->id = tempId;
            strcpy(minNode->type, tempType);
            minNode->duration = tempDuration;
            minNode->calories = tempCalories;
            strcpy(minNode->date, tempDate);
        }

        current = current->next;
    }

    printf("Da sap xep hoat dong theo calories (tang dan)!\n");
}

void searchByType()
{
    if (head == NULL)
    {
        printf("Danh sach hoat dong trong!\n");
        return;
    }

    char searchType[50];
    printf("Nhap loai hoat dong can tim: ");
    fflush(stdin);
    fgets(searchType, sizeof(searchType), stdin);
    searchType[strcspn(searchType, "\n")] = 0;

    printf("\n--- KET QUA TIM KIEM ---\n");
    printf("%-5s %-20s %-10s %-10s %-15s\n", "ID", "Loai", "Thoi gian", "Calories", "Ngay");
    printf("-------------------------------------------------------------\n");

    Activity *current = head;
    int found = 0;

    while (current != NULL)
    {
        if (strstr(current->type, searchType) != NULL)
        {
            printf("%-5d %-20s %-10d %-10d %-15s\n",
                   current->id, current->type, current->duration,
                   current->calories, current->date);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("Khong tim thay hoat dong loai '%s'!\n", searchType);
    }
    printf("\n");
}

void freeMemory()
{
    Activity *current = head;
    while (current != NULL)
    {
        Activity *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main()
{

    int choice;

    printf("===========================================\n");
    printf("         HEALTH TRACKER SYSTEM\n");
    printf("===========================================\n");

    while (1)
    {
        printf("\n------------- HEALTH TRACKER -------------\n");
        printf("1. Them hoat dong trong ngay\n");
        printf("2. Hien thi danh sach hoat dong\n");
        printf("3. Xoa hoat dong\n");
        printf("4. Cap nhat thong tin hoat dong\n");
        printf("5. Thong ke tong calories tieu thu/ngay\n");
        printf("6. Sap xep hoat dong\n");
        printf("7. Tim kiem hoat dong\n");
        printf("8. Thoat chuong trinh\n");
        printf("------------------------------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            addActivity();
            break;
        case 2:
            displayActivities();
            break;
        case 3:
            deleteActivity();
            break;
        case 4:
            updateActivity();
            break;
        case 5:
            calculateCaloriesByDate();
            break;
        case 6:
            sortByCalories();
            break;
        case 7:
            searchByType();
            break;
        case 8:
            printf("Cam on ban\n");
            freeMemory();
            exit(0);
        default:
            printf("Lua chon khong hop le! Vui long chon tu 1-8.\n");
        }
    }

    return 0;
}