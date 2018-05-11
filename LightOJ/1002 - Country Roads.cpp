/***************************************************
 * Problem name : 1002 - Country Roads.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1002
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-07-29
 * Problem Type : Graph(MST)
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
#define MAX 503
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
struct Edge {
    ll u, v, w;
    bool operator <(const Edge &p) const {
        return w < p.w;
    }
};
ll par[MAX], visit[MAX], mx[MAX];
vector<Edge>E;
vector<ll>adj[MAX], W[MAX];
ll find(ll r) {
    if (par[r] == r) return r;
    else return par[r] = find(par[r]);
}
void MST(ll n) {
    sort(E.begin(), E.end());
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    ll cnt = 0, sz = E.size();
    for (int i = 0; i < sz; i++) {
        ll u = find(E[i].u);
        ll v = find(E[i].v);
        if (u != v) {
            par[u] = v;
            cnt++;
            ll x = E[i].u;
            ll y = E[i].v;
            ll ww = E[i].w;
            adj[x].push_back(y);
            adj[y].push_back(x);
            W[x].push_back(ww);
            W[y].push_back(ww);
            //~ printf("%d %d %d\n\n", x,y,ww);
            if (cnt == n - 1) break;
        }
    }
}
ll BFS(ll s, ll d) {
    if (s == d) return 0;
    queue<int>Q;
    visit[s] = 1;
    mx[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        //~ debug;
        int sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            ll v = adj[u][i];
            ll w = W[u][i];
            if (visit[v] == 0) {
                mx[v] = max(w, mx[u]);
                if (v == d) break;
                //~ printf("%d %d = %d\n", u,v, w);
                //~ return mx;
                visit[v] = 1;
                Q.push(v);
            }
        }
    }
    return mx[d];
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        visit[i] = 0;
        mx[i] = -1;
    }
}
void Clear() {
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
        W[i].clear();
        par[i] = 0;
    }
    E.clear();
}
int main () {
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    ll tc, n, m;
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &n, &m);
        if (m != 0) {
            for (int i = 0; i < m; i++) {
                ll u, v, w;
                scanf("%lld %lld %lld", &u, &v, &w);
                Edge get;
                get.u = u;
                get.v = v;
                get.w = w;
                E.push_back(get);
            }
            //~ debug;
            MST(n);
            ll s;
            scanf("%lld", &s);
            printf("Case %d:\n", t);
            for (int i = 0; i < n; i++) {
                mem();
                ll c = BFS(i, s);
                if (c == -1) printf("Impossible\n");
                else printf("%lld\n", c);

            }
            Clear();
        }
        else{
            ll s;
            scanf("%lld", &s);
            printf("Case %d:\n", t);
            for(int i = 0; i<n; i++){
                if(s == i) printf("0\n");
                else printf("Impossible\n");
            }
        }
    }
    return 0;
}

