/***************************************************
 * Problem Name : 12655 Trucks.cpp
 * Problem Link : https://uva.onlinejudge.org/external/126/12655.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-09-08
 * Problem Type : LCA
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
#define MAX 20005
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
vector<int>adj[MAX], cost[MAX];
int level[MAX], par[MAX];
int table[MAX][17], mn_rd[MAX][17];


struct Edge {
    int u, v, w;
    bool operator< (const Edge &p) const {
        return w > p.w;
    }
};
vector<Edge>e;
int find (int r) {
    if (par[r] == r) return r ;
    else return par[r]  = find (par[r]);
}
void MST (int n) {
    sort (e.begin(), e.end() );

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    int cnt = 0, sz = (int) e.size();

    for (int i = 0; i < sz; i++) {
        int u = find (e[i].u);
        int v = find (e[i].v);

        if (u != v) {
            par[u] = v;
            cnt++;
            adj[e[i].u].pb (e[i].v);
            adj[e[i].v].pb (e[i].u);
            cost[e[i].u].pb (e[i].w);
            cost[e[i].v].pb (e[i].w);

            if (cnt == n) break;
        }
    }
}


void dfs (int u, int p) {
    for (int i  = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        level[v] = level[u] + 1;
        par[v] = u;
        mn_rd[v][0] = cost[u][i];
        dfs (v, u);
    }
}

void LCA (int n) {
    //~ SET (table, -1);
    for (int i = 1; i <= n; i++) {
        table[i][0] = par[i];
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            if (table[i][j - 1] != -1) {
                int x = table[i][j - 1];
                table[i][j] = table[x][j - 1];
                mn_rd[i][j] = min (mn_rd[i][j - 1], mn_rd[x][j - 1]);

            } else {
                mn_rd[i][j] = mn_rd[i][j - 1];
                table[i][j] = -1;
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
int main () {
    __FastIO;
    int n, m, s;

    while (cin >> n >> m >> s) {
        for (int i = 1; i <= m ; i++) {
            Edge get;
            cin >> get.u >> get.v >> get.w;
            e.pb (get);
        }

        MST (n);
        par[1] = -1;
        level[1] = 0;
        mn_rd[1][0] = 100005;
        dfs (1, -1);
        LCA (n);

        for (int q = 1; q <= s; q++) {
            int u, v;
            cin >> u >> v;
            int x = LCA_Quary (u, v);
            int uu = level[u] - level[x];
            int vv = level[v] - level[x];
            int mn = 100005;

            for (int i = log2 (uu); i >= 0; i--) {
                if ( (1 << i) <= uu) {
                    mn = min (mn, mn_rd[u][i]);
                    u = table[u][i];
                    uu -= (1 << i);
                }

                if (uu == 0) break;
            }

            for (int i = log2 (vv); i >= 0; i--) {
                if ( (1 << i) <= vv) {
                    mn = min (mn, mn_rd[v][i]);
                    v = table[v][i];
                    vv -= (1 << i);
                }

                if (vv == 0) break;
            }

            cout << mn << "\n";
        }

        e.clear();

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
