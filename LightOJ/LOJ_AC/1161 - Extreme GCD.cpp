/***************************************************
 * Problem name : 1161 - Extreme GCD.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1161                       
 * OJ           : LOJ                                  
 * Verdict      : AC                  
 * Date         : 2017-11-09                         
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
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 10005
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
ll MF[MAX], d[MAX];
char ar[MAX];
void Mobius_Function(ll n) {
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
ll CPascal(ll n , ll r) {
    ll v = 1;
    for (ll i = 1; i <= r; i++) {
        v = v * (n + 1 - i) / i;
    }
    return v;
}
void divisor(ll n) {
    ll sq = sqrt(n);
    for (ll i = 1; i < sq; i++) {
        if (n % i == 0) {
            d[i]++;
            d[n / i]++;
        }
    }
    if (n % sq == 0) {
        if (sq * sq == n) d[sq]++;
        else {
            d[sq]++;
            d[n / sq]++;
        }
    }
}
int main () {
    Mobius_Function(MAX);
    ll tc, n;
    ll ar[MAX];
    scanf("%lld", &tc);
    for (ll t = 1; t <= tc; t++) {
        scanf("%lld", &n);
        for (ll i = 0; i < n; i++) {
            scanf("%lld", &ar[i]);
            divisor(ar[i]);
        }
        ll ans = CPascal(n, 4);
        for (ll i = 2; i < MAX; i++) {
            ll xx = CPascal(d[i], 4);
            ans += (xx * MF[i]);
        }
        printf("Case %lld: %lld\n", t, ans);
        SET(d);
    }
    return 0;
}

