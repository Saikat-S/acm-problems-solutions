/***************************************************
 * Problem name : 11503  Virtual Friends.cpp
 * Problem Link : https://uva.onlinejudge.org/external/115/11503.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 09.06.2017
 * Problem Type : Graph
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
ll par[MAX], flag,gm[MAX];
map<string, ll>mp;
ll findRepresentative(ll r) {
    if (par[r] == r) {
        return r;
    } else {
        par[r] = findRepresentative(par[r]);
    }

    return par[r];
}
ll setUnion(ll a, ll b) {
    ll u = findRepresentative(a);
    ll v = findRepresentative(b);
    ll r = gm[u];
    ll rr = gm[v];
    ll ans;
    if (u != v) {
		ans = r + rr;
        par[u] = v;
        ll x = findRepresentative(u);
         return gm[x] = ans;
    }
    return  rr;
}
int main () {
    ll tc, F;
    scanf("%lld", &tc);
    for (ll t = 1; t <= tc; t++) {
        scanf("%lld", &F);
        ll j = 1;
        for (ll i = 1; i <= F; i++) {
            string a, b;
            cin >> a >> b;
            if (mp[a] == 0) {
                mp[a] = j++;
                par[mp[a]] = mp[a];
                gm[mp[a]] = 1;
            }
            if (mp[b] == 0) {
                mp[b] = j++;
                par[mp[b]] = mp[b];
                gm[mp[b]] = 1;;
            }
            ll cnt = setUnion(mp[a], mp[b]);
            printf("%lld\n", cnt);
        }
        mp.clear();
    }
    return 0;
}

