#include <stdio.h>
#include <string.h>

#define MAX 100005

int main() {
    char line[100];
    int t;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &t);
    if (t > 20) return 1;

    while (t--) {
        char s[MAX];
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';
        int len = strlen(s);

        int stack[MAX];
        int top = -1;
        int max_len = 0;

        stack[++top] = -1;

        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                stack[++top] = i;
            } else {
                if (top != -1) top--;
                if (top != -1) {
                    int cur_len = i - stack[top];
                    if (cur_len > max_len) max_len = cur_len;
                } else {
                    stack[++top] = i;
                }
            }
        }

        printf("%d\n", max_len);
    }
    return 0;
}
