/***************************************************
 * Problem Name : 11624 - Fire!.cpp
 * Problem Link : https://uva.onlinejudge.org/external/116/11624.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-08-29
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
#define MAX 1005
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
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};


vector<pii>vec;
char str[MAX][MAX];
bool vis[MAX][MAX];
int dis[MAX][MAX];
int dis1[MAX][MAX];
int n, m;

bool isValid (int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && str[x][y] == '.' && !vis[x][y]) {
        return true;

    } else {
        return false;
    }
}


void bfs1 () {
    SET (vis, false);
    SET (dis1, 0);
    queue<pii>q;

    for (int i = 0; i < (int) vec.size(); i++) {
        q.push ({vec[i].first, vec[i].second});
        dis1[vec[i].first][vec[i].second] = 0;
        vis[vec[i].first][vec[i].second] = true;
    }

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];

            if (isValid (tx, ty) ) {
                dis1[tx][ty] = dis1[top.first][top.second] + 1;
                vis[tx][ty] = true;
                q.push ({tx, ty});
            }
        }
    }
}
int bfs (int sx, int sy) {
    SET (vis, false);
    SET (dis, 0);
    queue<pii>q;
    q.push ({sx, sy});
    vis[sx][sy] = true;
    dis[sx][sy] = 0;

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        if (top.first == 0  || top.first == n - 1 || top.second == 0
            || top.second == m - 1) {
            return dis[top.first][top.second] + 1;
        }

        for (int i = 0; i < 4; i++) {
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];

            if (isValid (tx, ty) ) {
                dis[tx][ty] = dis[top.first][top.second] + 1;
                vis[tx][ty] = true;

                if (dis[tx][ty] < dis1[tx][ty] || dis1[tx][ty] == 0) {
                    if (tx == 0  || tx == n - 1 || ty == 0 || ty == m - 1) {
                        return dis[tx][ty] + 1;
                    }

                    q.push ({tx, ty});
                }
            }
        }
    }

    return -1;
}


int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        int sx, sy;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> str[i][j];

                if (str[i][j] == 'J') {
                    sx = i, sy = j;

                } else if (str[i][j] == 'F') {
                    vec.pb ({i, j});
                }
            }
        }

        if (sx == 0  || sx == n - 1 || sy == 0 || sy == m - 1) {
            cout << 1 << "\n";

        } else {
            bfs1();
            int ans = bfs (sx, sy);

            if (ans == -1) {
                cout << "IMPOSSIBLE\n";

            } else {
                cout << ans << "\n";
            }
        }

        vec.clear();
    }

    return 0;
}
