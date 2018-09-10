/***************************************************
 * Problem Name : LCASQ - Lowest Common Ancestor.cpp
 * Problem Link : https://www.spoj.com/problems/LCASQ/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-09-07
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
#define MAX 100005
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

    for (int i = 0; i < n; i++) {
        table[i][0] = par[i];
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
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
    //~ __FastIO;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x;

        for (int j = 1; j <= x; j++) {
            cin >> v;
            adj[i].pb (v);
        }
    }

    par[0] = -1;
    dfs (0, -1);
    LCA (n);
    int Q;
    cin >> Q;

    for (int q = 1; q <= Q ; q++) {
        int u, v;
        cin >> u >> v;
        cout << LCA_Quary (u, v) << "\n";
    }

    return 0;
}
