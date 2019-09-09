/***************************************************
 * Problem Name : 1271 - Better Tour.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1271
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-03
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
vector<int>adj[MAX];
bool vis[MAX];
int par[MAX];
int dis[MAX];

void bfs (int s, int d) {
    SET (vis, false);
    queue<int>q;
    q.push (s);
    dis[s] = 0;
    vis[s] = true;

    while (!q.empty() ) {
        int u = q.front();
        q.pop();
        sort (all (adj[u]) );

        for (int v : adj[u]) {
            if (!vis[v]) {
                dis[v] = dis[u] + 1;
                par[v] = min (par[v], u);
                vis[v] = true;

                if (v == d) {
                    return;
                }

                q.push (v);
            }
        }
    }
}


int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n;
    int ar[MAX];
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        for (int i = 1; i < n; i++) {
            adj[ar[i]].pb (ar[i - 1]);
            adj[ar[i - 1]].pb (ar[i]);
        }

        for (int i = 0; i < MAX; i++) {
            par[i] = MAX;
        }

        bfs (ar[0], ar[n - 1]);
        vector<int>ans;
        ans.pb (ar[n - 1]);
        int v = ar[n - 1];

        while (1) {
            int u = par[v];
            ans.pb (u);

            if (u == ar[0]) break;

            v = u;
        }

        reverse (all (ans) );
        cout << "Case " << t << ":\n";

        for (int i = 0; i < (int) ans.size(); i++) {
            if (i != 0) cout << " ";

            cout << ans[i];
        }

        nl;

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
