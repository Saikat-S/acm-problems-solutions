/***************************************************
 * Problem Name : 1099 - Not the Best.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1099
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-04
 * Problem Type : Graph(bfs)
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
#define MAX 5005
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
struct node {
    int u, w;
    node (int _u, int _w) {
        u = _u;
        w = _w;
    }
};

bool operator < (node a, node b) {
    return a.w > b.w;
}

vector<int>adj[MAX], cost[MAX];
int dis[MAX], dis1[MAX];
int mn[MAX];



void dj (int s, int d) {
    priority_queue<node>q;
    q.push (node (s, 0) );
    dis[s] = 0;
    mn[s] = INF;

    while (!q.empty() ) {
        node top = q.top();
        int u = top.u;
        q.pop();

        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            int w = cost[u][i];

            if (dis[u] + w < dis[v]) {
                mn[v] = min (w, mn[u]);
                dis1[v] = dis[v];
                dis[v] = dis[u] + w;
                q.push (node (v, dis[v]) );

            } else {
                if (dis[u] + w != dis[v]) dis1[v] = min (dis1[v], dis[u] + w);
            }

            if (dis1[u] + w < dis1[v]) {
                if (dis1[u] + w != dis[v]) {
                    dis1[v] = dis1[u] + w;
                }
            }
        }
    }
}
void dj1 (int s, int d) {
    priority_queue<int>q;
    q.push (s);

    while (!q.empty() ) {
        int u = q.top();
        q.pop();

        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            int w = cost[u][i];
            int x1 = dis[v] + w;
            int x2 = dis1[v] + w;

            if ( (x1 < dis1[u] && x1 != dis[u]) || (x2 < dis1[u] && x2 != dis[u]) ) {
                if (min (x1, x2) != dis[u]) dis1[u] = min (x1, x2);
                else dis1[u] = max (x1, x2);

                q.push (v);
            }
        }
    }
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    int n, m;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb (v);
            adj[v].pb (u);
            cost[u].pb (w);
            cost[v].pb (w);
        }

        for (int i = 0; i < MAX; i++) {
            dis[i] = INF;
            dis1[i] = INF;
            mn[i] = INF;
        }

        dj (1, n);
        dj (1, n);
        dj1 (n, 1);
        cout << "Case " << t << ": ";
        int res1 = dis1[n];
        int res2 = dis[n] + 2 * mn[n];
        cout << min (res1, res2) << "\n";

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
/*
1
5 6
1 2 1
2 3 7
3 4 2
4 5 3
4 1 6
3 5 1

output : 11
*/
