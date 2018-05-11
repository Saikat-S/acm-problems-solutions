#include<stdio.h>
int main() {
    int i, tc, num, rem, count;

    scanf("%d", &tc);

    for ( i = 1; i <= tc; i++) {
        scanf("%d", &num);
        count =  0;
        while (num > 0) {
            rem = num % 2;
            if (rem == 1) {
                count++;
            }
            num = num / 2;
        }
        if (count % 2 == 0) {
            printf("Case %d: even\n", i);
        } else {
            printf("Case %d: odd\n", i);
        }
    }
    return 0;
}
