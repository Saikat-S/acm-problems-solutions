//~ AC
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf ("%d", &n);
    int nn = n;
    int nn_time = (n * 2) - 1;
    static int ar[1003][2003];

    for (int i = 0; i < 1003; i++) {
        for (int j = 0; j < 2003; j++) {
            ar[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i, c = 0; ; j++) {
            ar[i][j] = nn;
            c++;

            if (c >= nn_time) break;
        }

        nn_time -= 2;
        nn--;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (2 * n) - 1; j++) {
            if (ar[i][j] == 0 ) {
                ar[i][j] = ar[i - 1][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (2 * n) - 1; j++) {
            printf ("%d ", ar[i][j]);
        }

        printf ("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= (2 * n) - 1; j++) {
            printf ("%d ", ar[i][j]);
        }

        printf ("\n");
    }

    return 0;
}
