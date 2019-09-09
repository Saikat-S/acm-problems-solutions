/***************************************************
 * Problem Name : 1257 - Farthest Nodes in a Tree (II).cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1257
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-08-29
 * Problem Type : Graph
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
#define pii pair<ll,ll>
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
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 30005
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
vector<int>adj[MAX], cost[MAX];
int dis[MAX];
bool vis[MAX];
void bfs (int s) {
    queue<int>q;
    vis[s] = true;
    dis[s] = 0;
    q.push (s);

    while (!q.empty() ) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            int w = cost[u][i];

            if (vis[v] == false) {
                dis[v] = dis[u] + w;
                vis[v] = true;
                q.push (v);
            }
        }
    }
}


int main () {
    //~ __FastIO;
    //~ cout.precision (10);
    //~ cout << fixed;
    int tc, n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb (v);
            adj[v].pb (u);
            cost[u].pb (w);
            cost[v].pb (w);
        }

        SET (vis, false);
        SET (dis, 0);
        bfs (0);
        int mx = 0, mx_node;
        int ans[MAX];
        SET (ans, 0);

        for (int i = 0; i < n; i++) {
            if (dis[i] > mx) {
                mx = dis[i];
                mx_node = i;
            }

            ans[i] = max (ans[i], dis[i]);
        }

        SET (vis, false);
        bfs (mx_node);
        mx = 0;

        for (int i = 0; i < n; i++) {
            if (dis[i] > mx) {
                mx = dis[i];
                mx_node = i;
            }

            ans[i] = max (ans[i], dis[i]);
        }

        SET (vis, false);
        bfs (mx_node);
        cout << "Case " << t << ":\n";

        for (int i = 0; i < n; i++) {
            ans[i] = max (ans[i], dis[i]);
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << "\n";
        }

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
