/***************************************************
 * Problem Name : Preparing for War.cpp
 * Problem Link : https://toph.co/p/preparing-for-war
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-12-25
 * Problem Type : Graph(AP)
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
#define MAX 500005
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
vector<int>adj[MAX];
int n, m, t, mx;

bool vis[MAX], chk[MAX];
int dis[MAX], low[MAX], ar[MAX];

void dfs1 (int u) {
    vis[u] = true;
    mx = max (mx, ar[u]);

    for (int v : adj[u]) {
        if (!vis[v]) dfs1 (v);
    }
}


void dfs (int u, int p) {
    vis[u] = true;
    dis[u] = low[u] = t++;
    int child  = 0;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        if (vis[v]) {
            low[u] = min (low[u], dis[v]);

        } else {
            dfs (v, u);
            low[u] = min (low[u], low[v]);

            if (dis[u] <= low[v] && p != -1) {
                chk[u] = true;
            }

            child++;
        }
    }

    if (p == -1 && child > 1) {
        chk[u] = true;
    }
}
void find_articulation_point() {
    t = 0;
    SET (vis, false);
    SET (chk, false);
    SET (dis, -1);
    SET (low, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs (i, -1);
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int k;
    cin >> n >> m >> k;
    vector<pii>vec;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vec.pb ({x, y});
        adj[x].pb (y);
        adj[y].pb (x);
    }

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    find_articulation_point();
    for(int i = 0; i<MAX; i++){
		adj[i].clear();
	}

    for (int i = 0; i < m; i++) {
        int x = vec[i].first;
        int y = vec[i].second;

        if (!chk[x] && !chk[y]) {
            adj[x].pb (y);
            adj[y].pb (x);
        }
    }

    vector<int>v;
    SET (vis, false);

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !chk[i]) {
            mx = 0;
            dfs1 (i);
            v.pb (mx);
        }
    }
    
    r_srt(v);
    
    ll sum = 0;
    
    for (int i = 0; i < min ( (int) v.size(), k); i++) {
        sum += (ll) v[i];
    }

    cout << sum << "\n";
    return 0;
}
