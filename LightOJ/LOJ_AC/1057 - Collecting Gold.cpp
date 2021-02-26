/***************************************************
 * Problem Name : 1057 - Collecting Gold.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1057
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2020-12-12
 * Problem Type : Bit Mask DP
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
#include <chrono>
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
#define un_map unordered_map
#define un_set unordered_set
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
struct custom_hash {
    static uint64_t splitmix64 (uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30) ) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27) ) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator() (uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                        chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64 (x + FIXED_RANDOM);
    }
};
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
vector<int>vec;
map<pii, int>mp;
map<int, pii>rmp;

int n, m, N, st;

int cost[19][19];

int fx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};


bool vis[23][23];
int dis[23][23];

void bfs (int sx, int sy) {
    memset (vis, 0, sizeof (vis) );
    memset (dis, 0, sizeof (dis) );
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push (pii (sx, sy) );
    dis[sx][sy] = 0;

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (tx >= 0 && ty >= 0 && tx < n && ty < m && vis[tx][ty] == 0) {
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[top.first][top.second] + 1;
                q.push (pii (tx, ty) );
            }
        }
    }

    int u = mp[ {sx, sy}];

    for (int i = 0; i < N; i++) {
        int v = vec[i];
        pii p = rmp[vec[i]];
        cost[u][v] = dis[p.F][p.S];
    }
}

int Set (int num, int pos) {
    return num = (num | (1 << pos) );
}
bool check (int num, int pos) {
    return (bool) (num & (1 << pos) );
}

int dp[19][65556];

int fun (int u, int mask) {
    if (mask == ( (1 << N) - 1) ) {
        return dp[u][mask] = cost[u][st];
    }

    int &res = dp[u][mask];

    if (res != -1) return res;

    res = INF;

    for (int i = 0; i < N; i++) {
        int v = vec[i];

        if (check (mask, i) == 0) {
            int tmp = cost[u][v] + fun (v, Set (mask, i) );
            res = min (res, tmp);
        }
    }

    return res;
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        int k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;

                if (ch == 'x' || ch == 'g') {
                    vec.pb (k);

                    if (ch == 'x') st = k;

                    rmp[k] = {i, j};
                    mp[ {i, j}] = k++;
                }
            }
        }

        N = (int) vec.size();

        for (int i = 0; i < N; i++) {
            pii p = rmp[vec[i]];
            bfs (p.F, p.S);
        }

        SET (dp, -1);
        int res = fun (st, 0);
        cout << "Case " << t << ": ";
        cout << res << "\n";
        vec.clear();
        mp.clear();
        rmp.clear();
        SET (cost, 0);
    }

    return 0;
}
