/***************************************************
 * Problem Name : ADAORANG - Ada and Orange Tree.cpp
 * Problem Link : https://www.spoj.com/problems/ADAORANG/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2019-09-19
 * Problem Type : LCA, Bitset
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
#define MAX 450010
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
/************************************ Code Start Here ******************************************************/
vector<vector<int> >adj;
bitset<251> ans[MAX];
int par[MAX], ar[MAX];
int table[MAX][20];
int level[MAX];
void dfs (int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;

        par[v] = u;
        level[v] = level[u] + 1;
        dfs (v, u);
        ans[u] |= ans[v];
    }
}
void build (int n) {
    for (int i = 1; i <= n; i++) {
        table[i][0] = par[i];
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            if (table[i][j - 1] != -1) {
                table[i][j] = table[table[i][j - 1]][j - 1];
            }
        }
    }
}
int query (int u, int v) {
    if (level[u] < level[v]) swap (u, v);

    int k = log2 (level[u]);

    for (int i = k; i >= 0; i--) {
        if ( (level[u] - (1 << i) ) >= level[v]) {
            u = table[u][i];
        }
    }

    if (u == v) return u;

    for (int i = k; i >= 0; i--) {
        if (table[u][i] != -1 && table[u][i] != table[v][i]) {
            u = table[u][i];
            v = table[v][i];
        }
    }

    return par[u];
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n, q, r;
    cin >> tc;

    while (tc--) {
        cin >> n >> q >> r;
        r++;
        adj.resize (n + 1);

        for (int i = 0; i <= n; i++) {
            ans[i].reset();
        }

        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
            ans[i][ar[i]] = 1;
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u++, v++;
            adj[u].pb (v);
            adj[v].pb (u);
        }

        par[r] = -1;
        level[r] = 0;
        SET (table, -1);
        dfs (r, -1);
        build (n);

        while (q--) {
            int u, v;
            cin >> u >> v;
            u++, v++;
            int nod = query (u, v);
            cout << ans[nod].count() << "\n";
        }

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
