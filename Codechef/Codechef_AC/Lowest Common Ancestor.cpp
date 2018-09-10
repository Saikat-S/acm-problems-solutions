/***************************************************
 * Problem Name : Lowest Common Ancestor.cpp
 * Problem Link : https://www.codechef.com/problems/TALCA
 * OJ           : Codechef
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
#define MAX 200005
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
int level[MAX], par[MAX];
int table[MAX][20];

void dfs (int u, int p) {
    for (int i  = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        level[v] = level[u] + 1;
        par[v] = u;
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

int getAns (int a, int b, int c) {
    if (a == b) return c;
    else if (b == c) return a;
    else return b;
}

int main () {
    __FastIO;
    int  n, Q;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    SET (level, 0);
    par[1] = -1;
    dfs (1, -1);
    LCA (n);
    cin >> Q;

    for (int q = 1; q <= Q; q++) {
        int r, u, v;
        cin >> r >> u >> v;
        int a = LCA_Quary (u, v);
        int b = LCA_Quary (r, u);
        int c = LCA_Quary (r, v);
        int ans  = getAns (a, b, c);
        cout << ans << "\n";
    }

    return 0;
}
