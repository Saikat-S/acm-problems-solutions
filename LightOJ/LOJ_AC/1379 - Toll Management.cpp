/***************************************************
 * Problem Name : 1379 - Toll Management.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1379
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-05
 * Problem Type : Graph(dijkstra)
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

struct node {
    int u, w;
    node (int _u, int _w) {
        u = _u;
        w = _w;
    }
};
struct edge {
    int u, v, w;
};

bool operator < (node a, node b) {
    return a.w > b.w;
}

vector<int> adj[MAX], cost[MAX];
vector<int> adj1[MAX], cost1[MAX];
int dis1[MAX];
int dis2[MAX];

void dj (int s) {
    priority_queue<node>q;
    q.push (node (s, 0) );
    dis1[s] = 0;

    while (!q.empty() ) {
        node top = q.top();
        int u = top.u;
        q.pop();

        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            int w = cost[u][i];

            if (dis1[u] + w < dis1[v]) {
                dis1[v] = dis1[u] + w;
                q.push (node (v, dis1[v]) );
            }
        }
    }
}
void dj1 (int s) {
    priority_queue<node>q;
    q.push (node (s, 0) );
    dis2[s] = 0;

    while (!q.empty() ) {
        node top = q.top();
        int u = top.u;
        q.pop();

        for (int i = 0; i < (int) adj1[u].size(); i++) {
            int v = adj1[u][i];
            int w = cost1[u][i];

            if (dis2[u] + w < dis2[v]) {
                dis2[v] = dis2[u] + w;
                q.push (node (v, dis2[v]) );
            }
        }
    }
}
void Clear() {
    for (int i = 0; i < MAX; i++) {
        dis1[i] = INF;
        dis2[i] = INF;
    }
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n, m, s, d, p;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d %d %d %d", &n, &m, &s, &d, &p);
        edge ar[m+3];

        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf ("%d %d %d", &u, &v, &w);
            adj[u].pb (v);
            cost[u].pb (w);
            adj1[v].pb (u);
            cost1[v].pb (w);
            ar[i].u = u;
            ar[i].v = v;
            ar[i].w = w;
        }

        Clear();
        dj (s);
        printf ("Case %d: ", t);

        if (dis1[d] == INF) {
            printf ("-1\n");

        } else {
            dj1 (d);
            int ans = -1;

            for (int i = 0; i < m; i++) {
                int u = ar[i].u;
                int v = ar[i].v;
                int w = ar[i].w;

                if (dis1[u] + dis2[v] + w <= p) {
                    ans = max (ans, w);
                }
            }

            printf ("%d\n", ans);
        }

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
            adj1[i].clear();
            cost1[i].clear();
        }
    }

    return 0;
}
/*
1
5 6 1 5 10
1 2 7
2 5 4
1 3 6
3 5 3
1 4 5
4 5 4
*/
