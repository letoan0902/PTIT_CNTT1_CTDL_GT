#include <stdio.h>
#include <string.h>

#define MAXN 1000005

char s[MAXN];
char left[MAXN], right[MAXN];
int ltop = 0, rtop = 0;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '<') {
            if (ltop) right[rtop++] = left[--ltop];
        } else if (s[i] == '>') {
            if (rtop) left[ltop++] = right[--rtop];
        } else if (s[i] == '-') {
            if (ltop) --ltop;
        } else {
            left[ltop++] = s[i];
        }
    }
    for (int i = 0; i < ltop; ++i) putchar(left[i]);
    for (int i = rtop-1; i >= 0; --i) putchar(right[i]);
    return 0;
}
