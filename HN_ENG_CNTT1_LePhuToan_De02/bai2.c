#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_ACTION_LENGTH 100

typedef struct
{
    char action[MAX_ACTION_LENGTH];
    char timestamp[20];
} GraphicAction;

typedef struct
{
    GraphicAction data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, GraphicAction action)
{
    if (isFull(stack))
    {
        printf("Stack đã đầy!\n");
        return;
    }
    stack->top++;
    strcpy(stack->data[stack->top].action, action.action);
    strcpy(stack->data[stack->top].timestamp, action.timestamp);
}

GraphicAction pop(Stack *stack)
{
    GraphicAction empty = {"", ""};
    if (isEmpty(stack))
    {
        printf("Stack rỗng!\n");
        return empty;
    }
    GraphicAction action = stack->data[stack->top];
    stack->top--;
    return action;
}

void getCurrentTimestamp(char *timestamp)
{
    strcpy(timestamp, "Moi nhat");
}

void clearStack(Stack *stack)
{
    stack->top = -1;
}

void drawAction(Stack *undoStack, Stack *redoStack)
{
    char actionInput[MAX_ACTION_LENGTH];
    GraphicAction newAction;

    printf("Nhap thao tac ve: ");
    fflush(stdout);
    fgets(actionInput, MAX_ACTION_LENGTH, stdin);

    actionInput[strcspn(actionInput, "\n")] = '\0';

    strcpy(newAction.action, actionInput);
    getCurrentTimestamp(newAction.timestamp);

    push(undoStack, newAction);

    clearStack(redoStack);

    printf("Da thuc hien thao tac ve: %s\n", newAction.action);
}

void undoAction(Stack *undoStack, Stack *redoStack)
{
    if (isEmpty(undoStack))
    {
        printf("Khong co thao tac nao de hoan tac!\n");
        return;
    }

    GraphicAction action = pop(undoStack);

    push(redoStack, action);

    printf("Da hoan tac thao tac: %s\n", action.action);
}

void redoAction(Stack *undoStack, Stack *redoStack)
{
    if (isEmpty(redoStack))
    {
        printf("Khong co thao tac nao de phuc hoi!\n");
        return;
    }

    GraphicAction action = pop(redoStack);

    push(undoStack, action);

    printf("Da phuc hoi thao tac: %s\n", action.action);
}

void printAllActions(Stack *undoStack)
{
    if (isEmpty(undoStack))
    {
        printf("Chua co thao tac ve nao!\n");
        return;
    }

    printf("\n========== DANH SACH THAO TAC VE ==========\n");
    printf("%-5s %-40s\n", "STT", "Thao tac");
    printf("-----------------------------------------------\n");

    for (int i = 0; i <= undoStack->top; i++)
    {
        printf("%-5d %-40s\n",
               i + 1,
               undoStack->data[i].action);
    }
    printf("-----------------------------------------------\n");
    printf("Tong so thao tac: %d\n\n", undoStack->top + 1);
}

void displayMenu()
{
    printf("\n");
    printf("-------- DRAW SIMULATOR --------\n");
    printf("1. DRAW: Thuc hien thao tac ve\n");
    printf("2. UNDO: Hoan tac thao tac gan nhat\n");
    printf("3. REDO: Phuc hoi thao tac vua UNDO\n");
    printf("4. PRINT: In toan bo thao tac (ve) da thuc hien\n");
    printf("5. EXIT: ket thuc chuong trinh\n");
    printf("-------------------------------\n");
    printf("Nhap lua chon cua ban: ");
}

int main()
{
    Stack undoStack, redoStack;
    char choice[10];

    initStack(&undoStack);
    initStack(&redoStack);

    printf("CHUONG TRINH MO PHONG VE DON GIAN\n");
    printf("==================================\n");

    while (1)
    {
        displayMenu();
        fgets(choice, sizeof(choice), stdin);

        switch (choice[0])
        {
        case '1':
            drawAction(&undoStack, &redoStack);
            break;
        case '2':
            undoAction(&undoStack, &redoStack);
            break;
        case '3':
            redoAction(&undoStack, &redoStack);
            break;
        case '4':
            printAllActions(&undoStack);
            break;
        case '5':
            printf("Thoat khoi chuong trinh...\n");
            return 0;

        default:
            printf("Lua chon khong hop le! Vui long chon lai.\n");
            break;
        }
    }

    return 0;
}
