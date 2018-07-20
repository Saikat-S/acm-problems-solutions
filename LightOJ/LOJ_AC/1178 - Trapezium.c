#include<stdio.h>
#include<math.h>
int main() {
    int tc, i;
    double a, b, c, d, area, h;

    scanf("%d", &tc);

    for (i = 1; i <= tc; i++) {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        double h1 = 2 * (a - c);
        double h2 = b * b;
        double h3 = d * d;
        double h4 = (a - c) * (a - c);
        double h5 = (h2 - h3 + h4) / h1;

        h = sqrt(h2 - h5 * h5);

        area = (h * (a + c)) / 2.0;

        printf("Case %d: %lf\n", i, area);


    }
    return 0;
}
