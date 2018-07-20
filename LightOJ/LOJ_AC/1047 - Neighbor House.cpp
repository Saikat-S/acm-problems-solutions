#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define MAX 25
#define SET(a) memset(a,-1,sizeof(a))
using namespace std;
int n;
int R[MAX], B[MAX], G[MAX];  ///R = 1, G = 2, B = 3;
int dp[4][MAX];
int KnapSack(int p, int i) {
    if (i == n) return 0;
    if (dp[p][i] != -1) return dp[p][i];
    int ans = 0;
    if (p == 1) {
        int val1 = G[i] + KnapSack(2, i + 1);
        int val2 = B[i] + KnapSack(3, i + 1);
        ans  += min(val1, val2);
    } else if (p == 2) {
        int val1 = R[i] + KnapSack(1, i + 1);
        int val2 = B[i] + KnapSack(3, i + 1);
        ans += min(val1, val2);
    } else if (p == 3) {
        int val1 = R[i] + KnapSack(1, i + 1);
        int val2 = G[i] + KnapSack(2, i + 1);
        ans += min(val1, val2);
    }

    return dp[p][i] = ans;
}
int main() {
    int tc;
    scanf("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf("%d", &n);
        for (int i =  0; i < n; i++) {
            scanf("%d %d %d", &R[i], &G[i], &B[i]);
        }
        SET(dp);
        int r = KnapSack(1, 0);
        int g = KnapSack(2, 0);
        int b = KnapSack(3, 0);
        int ans = min(r, min(g, b));

        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
