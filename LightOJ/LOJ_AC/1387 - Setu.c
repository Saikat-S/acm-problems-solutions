#include<stdio.h>
#include<string.h>
int main() {
    int tc, i, d, sum, n;
    char s[15];

    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &n);
        sum = 0;
        printf("Case %d:\n", t);
        for (i = 1; i <= n; i++) {
            scanf("%s", s);
            if (strcmp(s, "donate") == 0) {
                scanf("%d", &d);
                sum += d;
            } else {
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}
