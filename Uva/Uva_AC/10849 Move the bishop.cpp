/***************************************************
 * Problem name : 10849 Move the bishop.cpp
 * Problem Link : https://uva.onlinejudge.org/external/108/10849.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-26
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
#define MAX 100000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd (ll a, ll b) {
    if (a % b == 0) return b;

    return gcd (b, a % b);
}
ll lcm (ll a, ll b) {
    return a * b / gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    ll tc, n, M;
    scanf ("%lld", &tc);

    for (ll t = 1; t <= tc; t++) {
        scanf ("%lld %lld", &n, &M);

        for (ll q = 1; q <= n; q++) {
            ll x, y, a, b;
            scanf ("%lld %lld %lld %lld", &x, &y, &a, &b);
            ll xx = x + a, yy = y + b;

            if (x == a && y == b) printf ("0\n");
            else if ( (xx % 2 == 0 && yy % 2 == 0) || (xx % 2 == 1 && yy % 2 == 1) ) {
                if ( ( x == y && a == b) || ( (a != b)
                                              && ( (x + y) == (a + b) ) ) ) printf ("1\n");
                else if ( (xx % 2 == 1 && yy % 2 == 1 && (abs (x - a) == abs (y - b) ) )
                          || (xx % 2 == 0 && yy % 2 == 0
                              && (abs (x - a) == abs (y - b) ) ) ) printf ("1\n");
                else printf ("2\n");

            } else {
                printf ("no move\n");
            }
        }
    }

    return 0;
}

