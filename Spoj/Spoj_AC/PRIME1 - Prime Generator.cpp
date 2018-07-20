/***************************************************
 * Problem name : PRIME1 - Prime Generator.cpp
 * Problem Link : http://www.spoj.com/problems/PRIME1/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2017-10-07
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
bool isPrime(ll n) {
    if (n == 1) return 0;
    ll sq = sqrt(n);
    for (ll i = 2; i <= sq; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main () {
    int tc;
    ll m, n;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &m, &n);
        for (ll i = m; i <= n; i++) {
            if (isPrime(i)) {
                printf("%lld\n", i);
            }
        }
    }
    return 0;
}

