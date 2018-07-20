/***************************************************
 * Problem name : 371 ackermann Functions.cpp
 * Problem Link : https://uva.onlinejudge.org/external/3/371.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-04
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
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
#define MAX 100005
#define INF 1000000000
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
int main () {
    ll L, R;
    while (scanf("%lld %lld", &L, &R) == 2 && L != 0 && R != 0) {
        ll ans = 0, mx = 0;
        for (ll i = min(L, R); i <= max(L, R); i++) {
            ll X = i;
            ll cnt = 1;
            if (X % 2 == 0) {
                X /= 2;
            } else {
                X = 3 * X + 1;
            }
            while (X != 1) {
                if (X % 2  == 0) {
                    X /= 2;
                    cnt++;
                } else {
                    X = 3 * X + 1;
                    cnt++;
                }
            }
            if (cnt > mx) {
                mx = cnt;
                ans = i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", min(L, R), max(L, R), ans, mx);
    }

    return 0;
}
