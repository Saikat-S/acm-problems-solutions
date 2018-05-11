/***************************************************
 * Problem name : 908 - Re-connecting Computer Sites.cpp
 * Problem Link : https://uva.onlinejudge.org/external/9/908.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2017-08-07                         
 * Problem Type : MST                               
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
ll par[MAX];
struct edge {
    ll u, v, w;
    bool operator<(const edge &p)const {
        return w < p.w;
    }
};
vector<edge>e;
//~ vector<Edge>Ed;
ll find(ll r) {
    if (par[r] == r) return r ;
    else return par[r]  = find(par[r]);
}
ll MST(ll n) {
    sort(e.begin(), e.end());
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    ll cnt = 0, s = 0, sz = e.size();
    for (int i = 0; i < sz; i++) {
        ll u = find(e[i].u);
        ll v = find(e[i].v);
        if (u != v) {
            par[u] = v;
            cnt++;
            s += e[i].w;
            if (cnt == n) break;
        }
    }
    return s;
}
void Clear() {
    for (int i = 0; i < MAX; i++) {
        par[i] = 0;
    }
    e.clear();
}
int main () {
    ll N, t = 1;
    while (scanf("%lld", &N) == 1) {
        for (int i = 1 ; i < N; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }
        ll mx1 = MST(N);
        ll n, nn;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }
        scanf("%lld", &nn);
        for (int i = 1; i <= nn; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }
        ll mx2 = MST(N);
        if(t!=1) nl;
        printf("%lld\n%lld\n", mx1, mx2);
        t++;
        Clear();
    }
    return 0;
}
