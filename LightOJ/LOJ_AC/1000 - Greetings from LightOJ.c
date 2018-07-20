#include<stdio.h>
int main() {
    int i, tc, a, b;

    scanf("%d", &tc);
    for (i = 1; i <= tc; i++) {
        scanf("%d %d", &a, &b);

        printf("Case %d: %d\n", i, a + b);

    }
    return 0;
}
