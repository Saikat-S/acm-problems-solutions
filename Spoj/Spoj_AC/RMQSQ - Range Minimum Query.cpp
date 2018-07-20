/***************************************************
 * Problem name : RMQSQ - Range Minimum Query.cpp
 * OJ           : Spoj
 * Result       : AC
 * Date         : 24-03-17
 * Problem Type : SparseTable
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
#define pii pair<int,int>
#define MAX 100005
#define SET(a) memset(a,-1,sizeof(a))
using namespace std;
typedef long long ll;
ll ar[MAX];
ll st[MAX][16];
void build_st(ll n) {
    for (int i = 0; i < n; i++) st[i][0] = i;
    for (int j = 1; j <= 1<<j; j++) {
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
    ll n;
    scanf("%lld ", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld ", &ar[i]);
    }
    SET(st);
    build_st(n);
    ll q;
    scanf("%lld", &q);
    for (int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%lld\n", ar[query(x, y)]);
    }
    return 0;
}
