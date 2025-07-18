#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 13
#define MAX_COUNT 8192

char results[MAX_COUNT][MAX_LEN];
int result_count;

void generate(int n, char *current, int index) {
    if (index == n) {
        strcpy(results[result_count++], current);
        return;
    }
    current[index] = '6';
    generate(n, current, index + 1);
    current[index] = '8';
    generate(n, current, index + 1);
    current[index] = '\0';
}

int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);

        result_count = 0;
        char current[MAX_LEN] = "";
        generate(N, current, 0);

        qsort(results, result_count, sizeof(results[0]), compare);

        printf("%d\n", result_count);
        for (int i = 0; i < result_count; i++) {
            printf("%s", results[i]);
            if (i < result_count - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}