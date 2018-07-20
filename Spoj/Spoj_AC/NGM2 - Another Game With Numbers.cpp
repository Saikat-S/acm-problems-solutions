/***************************************************
 * Problem name : NGM2 - Another Game With Numbers.cpp
 * Problem Link : http://www.spoj.com/problems/NGM2/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2017-10-30
 * Problem Type : Inclusion-Exclusion
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
ll bitMask_inclusion(ll N, ll k, ll ar[]) {
    ll ans = 0;
    for (ll mask = 1; mask < (1 << k); mask++) {
        ll cnt = 0, lc = 1;
        for (ll i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                lc = lcm(lc, ar[i]);
                cnt++;
            }
        }
        if (cnt % 2 == 0) ans -= N / lc;
        else ans += N / lc;
    }
    return ans;
}
int main () {
    ll N, k, ar[MAX];
    scanf("%lld %lld", &N, &k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &ar[i]);
    }
    printf("%lld\n", N - bitMask_inclusion(N, k, ar));
    return 0;
}
