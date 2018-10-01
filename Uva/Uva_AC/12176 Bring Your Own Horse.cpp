/***************************************************
 * Problem Name : 12176 Bring Your Own Horse.cpp
 * Problem Link : https://uva.onlinejudge.org/external/121/12176.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-09-14
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
#define MAX 3005
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
vector<int>cost[MAX];
int par[MAX], level[MAX];
int mx_rd[MAX][15], table[MAX][15];
struct Edge {
    int u, v, w;
};
bool cmp (Edge a, Edge b) {
    return  a.w < b.w;
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
//~ int bfs (int s, int d) {
//~ SET (vis, false);
//~ queue<int>Q;
//~ vis[s] = true;
//~ mx[s] = 0;
//~ Q.push (s);

//~ while (!Q.empty() ) {
//~ int u = Q.front();
//~ Q.pop();

//~ for (int i = 0; i < (int) adj[u].size(); i++) {
//~ int v = adj[u][i];

//~ if (!vis[v]) {
//~ vis[v] = true;
//~ mx[v] = max (mx[u], cost[u][i]);

//~ if (v == d) return mx[d];

//~ Q.push (v);
//~ }
//~ }
//~ }

//~ return mx[d];
//~ }

void dfs (int u, int p) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        level[v] = level[u] + 1;
        par[v] = u;
        mx_rd[v][0] = cost[u][i];
        dfs (v, u);
    }
}
void LCA (int n) {
    SET (table, -1);

    for (int i = 1; i <= n; i++) {
        table[i][0] = par[i];
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            if (table[i][j - 1] != -1) {
                int x = table[i][j - 1];
                table[i][j] = table[x][j - 1];
                mx_rd[i][j] = max (mx_rd[i][j - 1], mx_rd[x][j - 1]);

            } else {
                mx_rd[i][j] = mx_rd[i][j - 1];
            }
        }
    }
}

int LCA_Quary (int u, int v) {
    if (level[u] < level[v]) swap (u, v);

    int lim = log2 (level[u]);

    for (int i = lim; i >= 0; i--) {
        if (level[u] - (1 << i) >= level[v]) {
            u = table[u][i];
        }
    }

    if (u == v) return u;

    for (int i = lim; i >= 0; i--) {
        if (table[u][i] != -1 && table[u][i] != table[v][i]) {
            u = table[u][i];
            v = table[v][i];
        }
    }

    return par[u];
}
int getMAX (int u, int uu) {
	int mx = 0;
    for (int i = log2 (uu); i >= 0; i--) {
        if ( (1 << i) <= uu) {
            mx = max (mx, mx_rd[u][i]);
            u = table[u][i];
            uu -= (1 << i);
        }

        if (uu == 0) break;
    }
    return mx;
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
        par[1] = -1;
        level[1] = 0;
        mx_rd[1][0] = 0;
        dfs (1, -1);
        LCA (N);
        int Q;
        cin >> Q;
        cout << "Case " << t << "\n";

        for (int q = 1; q <= Q; q++) {
            int u, v;
            cin >> u >> v;
            int x = LCA_Quary (u, v);
            int uu = level[u] - level[x];
            int vv = level[v] - level[x];
            cout << max(getMAX(u, uu), getMAX(v, vv))<<"\n";
            //~ mx[u] = 0;
            //~ dfs (u, -1, v);
            //~ cout << bfs (u, v) << "\n";
        }

        nl;
        E.clear();

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
