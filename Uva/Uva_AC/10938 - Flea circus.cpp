/***************************************************
 * Problem Name : 10938 - Flea circus.cpp
 * Problem Link : https://uva.onlinejudge.org/external/109/10938.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-09-20
 * Problem Type : Graph (LCA)
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
#define MAX 5005
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
int level[MAX], par[MAX], dis[MAX];
int table[MAX][15];

void dfs (int u, int p) {
    for (int i  = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        level[v] = level[u] + 1;
        par[v] = u;
        dis[v] = dis[u] + 1;
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
    int n;

    while (cin >> n) {
        if (n == 0) break;

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb (v);
            adj[v].pb (u);
        }

        SET (level, 0);
        SET (par, 0);
        SET (dis, 0);
        par[1] = -1;
        dfs (1, -1);
        LCA (n);
        int L;
        cin >> L;

        for (int q = 1; q <= L; q++) {
            int u, v;
            cin >> u >> v;
            int x = LCA_Quary (u, v);
            int ans = (dis[u] + dis[v]) - 2 * dis[x];

            if (ans % 2 == 1) {
                x  = ans / 2;

                if (level[u] < level[v]) swap (u, v);

                int lim = log2 (x);

                for (int i = lim; i >= 0; i--) {
                    if ( (1 << i) <= x) {
                        u = table[u][i];
                        x -= (1 << i);
                    }

                    if (x == 0) break;
                }

                cout << "The fleas jump forever between " << par[u] << " and " << u << ".\n";

            } else {
                x  = ans / 2;

                if (level[u] < level[v]) swap (u, v);

                int lim = log2 (x);

                for (int i = lim; i >= 0; i--) {
                    if ( (1 << i) <= x) {
                        u = table[u][i];
                        x -= (1 << i);
                    }

                    if (x == 0) break;
                }

                cout << "The fleas meet at " << u << ".\n";
            }
        }

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
