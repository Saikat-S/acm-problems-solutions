/***************************************************
 * Problem Name : Dijkstra: Shortest Reach 2.cpp
 * Problem Link : https://www.hackerrank.com/challenges/dijkstrashortreach/problem
 * OJ           : HackerRank
 * Verdict      : AC
 * Date         : 2019-09-12
 * Problem Type : Graph (dijkstra)
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
#define MAX 3005
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

struct node {
    int x, w;
    node (int a, int c) {
        x = a;
        w = c;
    }
};
bool operator < (node a, node b) {
    return a.w > b.w;
}
void dijkstra (int s) {
    priority_queue<node>Q;
    Q.push (node (s, 0) );
    dis[s] = 0;

    while (!Q.empty() ) {
        node top = Q.top();
        int u = top.x;
        Q.pop();

        for (int i = 0; i < (int) SZ (adj[u]); i++) {
            int v = adj[u][i];
            int w = cost[u][i];

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                Q.push (node (v, dis[v]) );
            }
        }
    }
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n, m;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        vector<int>Ed;
        map<pii, int>mp;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            if (u > v) swap (u, v);

            if (mp[ {u, v}] == 0) {
                mp[ {u, v}] = w;

            } else {
                mp[ {u, v}] = min (mp[ {u, v}], w);
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int u = it->first.first;
            int v = it->first.second;
            int w = it->second;
            adj[u].pb (v);
            adj[v].pb (u);
            cost[u].pb (w);
            cost[v].pb (w);
        }

        for (int i = 0; i < MAX; i++) {
            dis[i] = INF;
        }

        int s;
        cin >> s;
        dijkstra (s);

        for (int i = 1; i <= n; i++) {
            if (dis[i] == INF) dis[i] = -1;

            if (i != s) cout << dis[i] << " ";
        }

        nl;

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
