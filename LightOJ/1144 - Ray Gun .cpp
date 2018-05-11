/***************************************************
 * Problem name : 1144 - Ray Gun .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1144
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-11-05
 * Problem Type : Number Theory
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
#define MAX 1000005
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
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
ll MF[MAX];
char ar[MAX];
void  Mobius_Function(ll n) {
    ar[0] = ar[1] = 1;
    for (ll i = 1; i < n; i++) MF[i] = 1;
    for (ll i = 2; i < n; i++) {
        if (ar[i] == 0) {
            MF[i] = -1;
            for (ll j = i + i; j < n; j += i) {
                if (j % (i * i) == 0)MF[j] = 0;
                ar[j] = 1;
                MF[j] = (-1) * MF[j];
            }
        }
    }
}
int main () {
    Mobius_Function(MAX);
    int tc;
    ll m, n;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &m, &n);
        if (m == n && n == 0) {
            printf("Case %d: 0\n", t);
            continue;
        }
        if (m == 0 || n == 0) {
            printf("Case %d: 1\n", t);
            continue;
        }
        ll ans = (n * m);
        for (ll i = 2; i <= min(m, n); i++) {
            ans += (MF[i] * ((n / i) * (m / i)));
        }
        printf("Case %d: %lld\n",t,  ans + 2);
    }
    return 0;
}
