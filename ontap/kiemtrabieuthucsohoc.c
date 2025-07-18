#include <stdio.h>
#include <string.h>


int check(char* input){
    char stack[10000];
    int top=-1;
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if(input[i]==')'){
            int cotoantu=0;
            while(stack[top]!='('&&top!=-1){
                if(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/'){
                    cotoantu=1;
                }
                top--;
            }
            if(top==-1){
                return 1;
            } else {
                if(cotoantu){
                    top--;
                } else {
                    return 1;
                }
            }
        } else {
            stack[++top]=input[i];
        }
    }
    return 0;
}

int main(){
    int t;
    char line[1000];
    fgets(line,1000,stdin);
    sscanf(line,"%d",&t);
    while(t--){
        char input[10000];
        fgets(input, 10000, stdin);
        input[strcspn(input,"/n")]='\0';

        if(check(input)){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}