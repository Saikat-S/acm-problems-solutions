/***************************************************
 * Problem name : 12959 Strategy Game.cpp
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 29.06.2017
 * Problem Type : AdHoc
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX  250005
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    int J, R;
    int ar[MAX], P[503];
    while (scanf("%d %d", &J, &R) == 2) {
        for (int i = 1; i <= J * R; i++) {
            scanf("%d", &ar[i]);
        }
        int mx = 0, ans;
        for (int i = 1; i <= J; i++) {
			P[i] = 0;
            for (int j = i; j <= J * R; j += J) {
                P[i] = P[i] + ar[j];
            }
            if (mx <= P[i]) {
                mx = P[i];
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

