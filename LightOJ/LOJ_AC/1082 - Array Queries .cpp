/***************************************************
 * Problem name : 1082 - Array Queries .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1082
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 19.05.2017
 * Problem Type :
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define debug printf("#########\n")
#define nl printf("\n")
#define MAX 100005
using namespace std;
typedef long long ll;
ll ar[MAX];
ll st[MAX][16];
void build_st(ll n) {
    for (int i = 0; i < n; i++) st[i][0] = i;
    for (int j = 1; j <= 1 << j; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            ll x = st[i][j - 1];
            ll y = st[i + (1 << (j - 1))][j - 1];
            if (ar[x] <= ar[y]) st[i][j] = x;
            else st[i][j] = y;
        }
    }
}
int query(ll lb, ll ub) {
    ll cnt = ub - lb + 1;
    ll k = log2(cnt);
    ll x = st[lb][k];
    ll y = st[ub - (1 << k) + 1][k];
    if (ar[x] <= ar[y]) return x;
    else return y;
}
int main () {
    int tc;
    ll n, q;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &n, &q);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &ar[i]);
        }
        build_st(n);
        printf("Case %d:\n", t);
        for (int i = 1; i <= q; i++) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", ar[query(x-1, y-1)]);
        }
    }
    return 0;
}

