/***************************************************
 * Problem Name : 1300 - Odd Personality.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1300
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-10
 * Problem Type : Grapg (Bridge)
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
#define MAX 100005
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
vector<int>adj[MAX], graph[MAX];

map<pii, bool>mp;

int dis[MAX], low[MAX], T, cnt;
bool vis[MAX];
int color[MAX], flag;       // green = 1, red = 2;

void dfs (int u, int p) {
    vis[u] = true;
    dis[u] = T;
    low[u] = T++;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (vis[v]) {
            low[u] = min (low[u], dis[v]);

        } else {
            dfs (v, u);
            low[u] = min (low[u], low[v]);

            if (dis[u] < low[v]) {
                mp[ {min (u, v), max (u, v) }] = true;
            }
        }
    }
}

void solve (int n) {
    T = 0;
    SET (vis, false);
    SET (dis, -1);
    SET (low, -1);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs (i, -1);
        }
    }
}

void dfs3 (int u) {
    cnt++;
    vis[u] = true;

    for (int v : graph[u]) {
        if (!vis[v]) dfs3 (v);
    }
}

void dfs1 (int u) {
    if (flag == 1) return ;

    if (color[u] == 0) {
        color[u] = 1;
    }

    for (int i = 0; i < (int) graph[u].size(); i++) {
        int v = graph[u][i];

        if (color[v] == 0) {
            if (color[u] == 1) {
                color[v] = 2;
                dfs1 (v);

            } else {
                dfs1 (v);
            }
        }

        if (color[u] == color[v]) {
            flag = 1;
            return ;
        }
    }
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n, m;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        vector<pii>vec;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb (v);
            adj[v].pb (u);

            if (u > v) {
                swap (u, v);
            }

            vec.pb ({u, v});
        }

        solve (n);

        for (int i = 0; i < (int) vec.size(); i++) {
            int u = vec[i].first;
            int v = vec[i].second;

            if (!mp[vec[i]]) {
                graph[u].pb (v);
                graph[v].pb (u);

            } else {
            }
        }

        SET (vis, false);
        SET (color, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt = 0;
                dfs3 (i);
                flag = 0;
                dfs1 (i);

                if (flag == 1 && cnt >= 3) res += cnt;
            }
        }

        cout << "Case " << t << ": ";
        cout << res << "\n";
        mp.clear();

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            graph[i].clear();
        }
    }

    return 0;
}
