#include <stdio.h>
#include <string.h>

char s[100005], line[100005];

int main() {
    int t;
    fgets(line, 100005, stdin);
    sscanf(line, "%d", &t);
    while (t--) {
        fgets(s, 100005, stdin);
        int len = strlen(s);
        if (s[len-1] == '\n') s[len-1] = 0;
        int ans = 0, open = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                if (open) open--;
                else {
                    ans++;
                    open++;
                }
            }
        }
        ans += open/2;
        printf("%d\n", ans);
    }
    return 0;
}
