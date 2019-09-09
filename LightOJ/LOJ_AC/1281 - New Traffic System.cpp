/***************************************************
 * Problem Name : 1281 - New Traffic System.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1281
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-04
 * Problem Type : Graha(dijkstra)
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
#define MAX 10005
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

int dis[MAX][13];
struct node {
    int u, w, c;
    node (int _u, int _w, int _c) {
        u = _u;
        w = _w;
        c = _c;
    }
};
bool operator < (node a, node b) {
    return a.w > b.w;
}
void dijkstra (int s, int d) {
    priority_queue<node>Q;
    Q.push (node (s, 0, 0) );
    dis[s][0] = 0;

    while (!Q.empty() ) {
        node top = Q.top();
        int u = top.u;
        int c = top.c;
        Q.pop();

        for (int i = 0; i < SZ (adj[u]); i++) {
            int v = adj[u][i];
            int w = cost[u][i];
            int cc = c;

            if (w < 0) {
                w *= -1;
                cc++;
            }

            if (c != cc) {
                if (cc > d) continue;
            }

            if (dis[u][c] + w < dis[v][cc] && cc <= d) {
                dis[v][cc] = dis[u][c] + w;
                Q.push (node (v, dis[v][cc], cc) );
            }
        }
    }
}
int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    int n, m, k, d;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m >> k >> d;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb (v);
            cost[u].pb (w);
        }

        for (int i = 0; i < k; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb (v);
            cost[u].pb (w * -1);
        }

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j <= 10; j++) {
                dis[i][j] = INF;
            }
        }

        dijkstra (0, d);
        cout << "Case " << t << ": ";
        int ans  = INF;

        for (int i = 0; i <= d; i++) {
            ans = min (ans, dis[n - 1][i]);
        }

        if (ans == INF) cout << "Impossible\n";
        else cout << ans << "\n";

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
/*
1
7 5 4 1
0 1 10
1 2 5
3 4 12
4 5 14
4 6 2
0 6 100
0 2 5
2 3 7
5 6 9
*/
