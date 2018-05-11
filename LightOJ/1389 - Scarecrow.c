#include<stdio.h>
int main() {
    int n, tc, i, j, count;
    char str[100];

    scanf("%d", &tc);

    for (i = 1; i <= tc; i++) {
        scanf("%d %s", &n, str);
        count = 0;
        for (j = 0; j < n;) {
            if (str[j] == '#') {
                j++;
            } else {
                count++;
                j = j + 3;
            }
        }

        printf("Case %d: %d\n", i, count);
    }
    return 0;
}
