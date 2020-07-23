/***************************************************
 * Problem Name : D.cpp
 * Problem Link :
 * OJ           :
 * Verdict      : AC
 * Date         : 2020-05-17
 * Problem Type :
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
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define F first
#define S second
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
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX];
bool vis[MAX];
int d[MAX];
void bfs (int s) {
    queue<int>q;
    q.push (s);
    vis[s] = 1;
    d[s] = 0;

    while (!q.empty() ) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                d[v] = d[u] + 1;
                q.push (v);
            }
        }
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb (y);
        adj[y].pb (x);
    }

    SET (vis, 0);
    bfs (1);
    bool f = 0;

    for (int i = 2; i <= n; i++) {
        if (vis[i] == 0) f = 1;
    }

    if (f) {
        cout << "No\n";

    } else {
        cout << "Yes\n";
        vector<int>vec (n + 1);

        for (int i = 2; i <= n; i++) {
            int mn = INF;
            int u = -1;

            for (auto v : adj[i]) {
                if (d[v] < mn) {
                    mn = d[v];
                    u = v;
                }
            }

            vec[i] = u;
        }

        for (int i = 2; i <= n; i++) {
            cout << vec[i] << "\n";
        }
    }

    return 0;
}
