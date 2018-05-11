#include<stdio.h>
int d_b(int num) {
    long bi, base, rem;

    bi = 0, base = 1;
    while (num > 0) {
        rem = num % 2;
        bi = bi + base * rem ;
        num = num / 2;
        base = base * 10;
    }

    return bi;
}
int main() {
    int i, tc, n1, n2, n3, n4;
    long n5, n6, n7, n8;
    char ch;

    scanf("%d", &tc);

    for ( i = 1; i <= tc; i++) {
        scanf("%d %c %d %c %d %c %d", &n1, &ch, &n2, &ch, &n3, &ch, &n4);

        scanf("%ld %c %ld %c %ld %c %ld", &n5, &ch, &n6, &ch, &n7, &ch, &n8);

        if (n5 == d_b(n1) && n6 == d_b(n2) && n7 == d_b(n3) && n8 == d_b(n4)) {
            printf("Case %d: Yes\n", i);
        } else {
            printf("Case %d: No\n", i);
        }
    }
    return 0;
}
