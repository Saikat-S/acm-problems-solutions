/***************************************************
 * Problem name : Roads and Libraries.cpp
 * Problem Link : https://www.hackerrank.com/challenges/torque-and-development/problem
 * OJ           : HackerRank
 * Verdict      : Ac
 * Date         : 2017-11-03
 * Problem Type : Graph Algo
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
#define MAX 100005
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
ll par[MAX], G[MAX];
void Union(ll n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        G[i] = 1;
    }
}
ll find(ll r) {
    if (par[r] == r) return r;
    else return par[r] = find(par[r]);
}
void make_union(ll x, ll y) {
    ll u = find(x);
    ll v = find(y);
    if (u != v) {
        par[u] = v;
        ll xx = find(u);
        G[xx] = G[u] + G[v];
    }
    //~ G[u] = G[x] + G[y];
}
int main () {
    ll tc, n, m, Rc, Lc;
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld %lld %lld", &n, &m, &Lc, &Rc);
        Union(n);
        for (int i = 0; i < m; i++) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            make_union(x, y);
        }
        if (Lc <= Rc) {
            printf("%lld\n", (n * Lc));
        } else {
            ll cost = 0;
            map<ll , int>mp;
            for (int i = 1; i <= n; i++) {
                ll y = find(i);
                if(mp[y] == 0){
                    cost = cost+Lc;
                    //~ printf("%lld\n", cost);
                    ll xx = G[y];
                    ll X = ((xx-1) * Rc);
                    cost= cost + X;
                     //~ printf("\n%lld %lld %lld\n", xx, cost, X);
                    mp[y] = 1;
                }
            }
            printf("%lld\n", cost);
        }
        SET(par);
        SET(G);
    }
    return 0;
}
