/***************************************************
 * Problem Name : MARYBMW - BMW.cpp
 * Problem Link : https://www.spoj.com/problems/MARYBMW/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-09-13
 * Problem Type : Graph (MST)
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 50005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX];
vector<ll>cost[MAX];
int par[MAX];
ll mn[MAX];
struct Edge {
    int u, v;
    ll w;
};
bool cmp (Edge a, Edge b) {
    return  a.w > b.w;
}
vector<Edge>E;

int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}
void MST (int n) {
    sort (all (E), cmp);

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    int cnt =  0;

    for (int i = 0; i < (int) E.size(); i++) {
        int u = find (E[i].u);
        int v = find (E[i].v);

        if (u != v) {
            par[u] = v;
            cnt++;
            adj[E[i].u].pb (E[i].v);
            adj[E[i].v].pb (E[i].u);
            cost[E[i].u].pb (E[i].w);
            cost[E[i].v].pb (E[i].w);

            if (cnt == n) break;
        }
    }
}
//~ bool vis[MAX];
//~ ll bfs (int s, int d) {
//~ SET (vis, false);
//~ queue<int>Q;
//~ vis[s] = true;
//~ mn[s] = 1000000000000000005;
//~ Q.push (s);

//~ while (!Q.empty() ) {
//~ int u = Q.front();
//~ Q.pop();

//~ for (int i = 0; i < (int) adj[u].size(); i++) {
//~ int v = adj[u][i];

//~ if (!vis[v]) {
//~ vis[v] = true;
//~ mn[v] = min (mn[u], cost[u][i]);

//~ if (v == d) return mn[d];

//~ Q.push (v);
//~ }
//~ }
//~ }

//~ return -1;
//~ }
bool flag;
void dfs (int u, int p, int d) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        mn[v] = min (mn[u], cost[u][i]);

        if (v == d) flag = 1;

        dfs (v, u, d);
    }
}
int main () {
    __FastIO;
    int tc, N, M;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> N >> M;

        for (int i = 1; i <= M; i++) {
            Edge get;
            cin >> get.u >> get.v >> get.w;
            E.pb (get);
        }

        MST (N);
        //~ ll ans = bfs (1, N);
        flag = 0;
        mn[1] = 1000000000000000005;
        dfs (1, -1, N);

        if (!flag) cout << "-1\n";
        else cout << mn[N] << "\n";

        E.clear();

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
