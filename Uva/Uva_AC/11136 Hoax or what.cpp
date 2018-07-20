/***************************************************
 * Problem name : 11136 Hoax or what.cpp
 * Problem Link : https://uva.onlinejudge.org/external/111/11136.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-25
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    ll n, k;
    map<ll, ll>mp;
    while (scanf("%lld", &n) == 1 && n != 0) {
        ll ans = 0;
        for (int d = 1; d <= n; d++) {
            scanf("%lld", &k);
            for (int c = 1; c <= k; c++) {
                ll x;
                scanf("%lld", &x);
                mp[x]++;
            }
            map<ll, ll>::iterator it;
            it = mp.begin();
            ll mn = it->first;
            it = mp.end();
            it--;
            ll mx = it->first;
            mp[mn]--;
            mp[mx]--;
            if (mp[mn] == 0) mp.erase(mn);
            if (mp[mx] == 0) mp.erase(mx);
            ans += (mx - mn);
        }
        printf("%lld\n", ans);
        mp.clear();
    }
    return 0;
}

