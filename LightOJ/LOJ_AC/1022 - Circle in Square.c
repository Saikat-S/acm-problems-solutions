#include<stdio.h>
int main() {
    int i, tc;
    double area, r, pi = 3.1415926535897932384626;

    scanf("%d", &tc);
    for (i = 1; i <= tc; i++) {
        scanf("%lf", &r);

        area = (4 * r * r) - (pi * r * r);

        printf("Case %d: %.2lf\n", i, area);
    }
    return 0;
}
