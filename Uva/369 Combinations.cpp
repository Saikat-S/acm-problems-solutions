/***************************************************
 * Problem name : 369 Combinations.cpp
 * Problem Link : https://uva.onlinejudge.org/external/3/369.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-10
 * Problem Type : AdHoc
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 105
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
ll C[MAX + 1][MAX + 1];
ll ncr(ll n, ll r) {
    if (C[n][r] == -1)
        C[n][r] = ncr(n - 1, r) + ncr(n - 1, r - 1);
    return C[n][r];
}
ll get_ncr(ll n, ll r) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            C[i][j] = -1;
        }
    }

    for (i = 1; i <= n; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }
    return ncr(n, r);
}
int main () {
    //~ __FastIO;
    ll n, m;
    while (scanf("%lld %lld", &n, &m) == 2 && n != 0 && m != 0) {
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, m, get_ncr(n, m));
    }
    return 0;
}
