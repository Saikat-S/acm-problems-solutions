/***************************************************
 * Problem Name : 1059 - Air Ports.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1059
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-09
 * Problem Type : Graph (MST)
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
struct Edge {
    int u, v, w;
    bool operator < (const Edge &p) const {
        return w < p.w;
    }
};
vector<Edge>Ed;
vector<int>adj[MAX], cost[MAX];
int par[MAX];
bool vis[MAX];
int cnt;
ll sum;

int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}

void mst (int n) {
    sort (all (Ed) );

    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }

    int cnt = 0;

    for (int i = 0; i < (int) Ed.size(); i++) {
        int u = find (par[Ed[i].u]);
        int v = find (par[Ed[i].v]);

        if (u != v) {
            par[u] = v;
            adj[Ed[i].u].pb (Ed[i].v);
            adj[Ed[i].v].pb (Ed[i].u);
            cost[Ed[i].u].pb (Ed[i].w);
            cost[Ed[i].v].pb (Ed[i].w);
            cnt++;

            if (cnt == n - 1) break;
        }
    }
}

void dfs (int u, int A) {
    vis[u] = true;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];
        ll w = cost[u][i];

        if (!vis[v]) {
            if (w >= A) {
                cnt++;

            } else {
                sum += w;
            }

            dfs (v, A);
        }
    }
}


int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    int n, m, A;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m >> A;

        for (int i = 0; i < m; i++) {
            Edge get;
            cin >> get.u >> get.v >> get.w;
            Ed.pb (get);
        }

        mst (n);
        sum = 0;
        cnt = 0;
        SET (vis, false);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs (i, A);
                cnt++;
            }
        }

        cout << "Case " << t << ": ";
        cout << (sum + ( (ll) cnt * (ll) A) ) << " " << cnt << "\n";
        Ed.clear();

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
