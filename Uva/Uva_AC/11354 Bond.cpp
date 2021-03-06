/***************************************************
 * Problem Name : 11354 Bond.cpp
 * Problem Link : https://uva.onlinejudge.org/external/113/11354.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-09-20
 * Problem Type : LCA,MST
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <deque>
#include <stack>
#include <bitset>
#include <cassert>
#include <map>
#include <set>
#include <cassert>
#include <iomanip>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin)
#define __FileWrite freopen ("output.txt", "w", stdout)
#define SET(a,v) memset(a,v,sizeof(a))
#define SZ(v) (int)v.size()
#define pii pair<int,int>
#define pil pair <int, ll>
#define pli pair <ll, int>
#define pll pair <ll, ll>
#define debug cout <<"######\n"
#define debug1(x) cout <<"### " << x << " ###\n"
#define debug2(x,y) cout <<"# " << x <<" : "<< y <<" #\n"
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define rall(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 50005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

template <typename T> string toString ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template<typename T> int toInt (T str) {
    stringstream ss;
    ss << str;
    int num;
    ss >> num;
    return num;
}
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
struct Edge {
    int u, v, w;
    bool operator< (const Edge &p) const {
        return w < p.w;
    }
};
vector<Edge>Ed;
vector<int>adj[MAX], cost[MAX];
int par[MAX], level[MAX];
int table[MAX][17], mx_rd[MAX][17];

int find (int r) {
    if (par[r] == r) return r ;
    else return par[r]  = find (par[r]);
}

void MST (int n) {
    sort (all (Ed) );

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    int cnt = 0;

    for (int i = 0; i < (int) Ed.size(); i++) {
        int u = Ed[i].u;
        int v = Ed[i].v;
        int w = Ed[i].w;
        int uu = find (u);
        int vv = find (v);

        if (uu != vv ) {
            par[vv] = uu;
            cnt++;
            adj[u].pb (v);
            adj[v].pb (u);
            cost[u].pb (w);
            cost[v].pb (w);

            if (cnt == n - 1) break;
        }
    }
}



void dfs (int u, int p) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        par[v] = u;
        level[v] = level[u] + 1;
        mx_rd[v][0] = cost[u][i];
        dfs (v, u);
    }
}

void build_lca (int n) {
    for (int i = 1; i <= n; i++) {
        table[i][0] = par[i];
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1 ; i <= n; i++) {
            if (table[i][j - 1] != -1) {
                int x = table[i][j - 1];
                table[i][j] = table[x][j - 1];
                mx_rd[i][j] = max (mx_rd[i][j - 1], mx_rd[x][j - 1]);

            } else {
                table[i][j] = -1;
                mx_rd[i][j] = mx_rd[i][j - 1];
            }
        }
    }
}

int query (int u, int v) {
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

int get_max (int u, int uu) {
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
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n, m;
    int t = 1;

    while (cin >> n >> m) {
        for (int i = 0; i < m ; i++) {
            Edge get;
            cin >> get.u >> get.v >> get.w;
            Ed.pb (get);
        }

        MST (n);
        par[1] = -1;
        level[1] = 0;
        SET (table, -1);
        mx_rd[1][0] = 0;
        dfs (1, -1);
        build_lca (n);
        int q;
        cin >> q;

        if (t != 1) nl;

        t++;

        while (q--) {
            int u, v;
            cin >> u >> v;
            int r = query (u, v);
            int uu = level[u] - level[r];
            int vv = level[v] - level[r];
            cout << max (get_max (u, uu), get_max (v, vv) ) << "\n";
        }

        Ed.clear();

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
