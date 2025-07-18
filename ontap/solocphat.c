#include <stdio.h>
#include <math.h>
#include <string.h>

long long int queue[100000];
int front=0;
int rear=0;

void push(long long int x){
    queue[rear++]=x;
}

long long int pop(){
    return queue[front++];
}

long long int peek(){
    return queue[front];
}

int empty(){
    return front==rear;
}

void check68(int n){
    int count=2;
    front=0;
    rear=0;
    push(6);
    push(8);

    while(front<rear){
        long long int a = peek();
        char str[25];
        int x = sprintf(str,"%lld",a*10+6);
        if(strlen(str)>n){
            printf("%d\n",count);
            for (int i = 0; i < rear; i++)
            {
                printf("%lld ",queue[i]);
            }
            printf("\n");
            break;
        }
        push(a*10+6);
        count++;
        push(a*10+8);
        count++;
        front++;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        check68(n);
    }
    return 0;
}