/***************************************************
 * Problem Name : D - Maze Master.cpp
 * Problem Link : https://atcoder.jp/contests/abc151/tasks/abc151_d
 * OJ           : atCoder
 * Verdict      : AC
 * Date         : 2020-01-12
 * Problem Type : ABC - D
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
#define MAX 25
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
int n, m;
char str[MAX][MAX];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool vis[MAX][MAX];
int dis[MAX][MAX];

void bfs (int sx, int sy) {
    SET (vis, false);
    SET (dis, 0);
    vis[sx][sy] = true;
    dis[sx][sy] = 0;
    queue <pii> q;
    q.push (pii (sx, sy) );

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (tx >= 0 && ty >= 0 && tx < n && ty < m && vis[tx][ty] == false
                && str[tx][ty] != '#') {
                vis[tx][ty] = true;
                dis[tx][ty] = dis[top.first][top.second] + 1;
                q.push (pii (tx, ty) );
            }
        }
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> str[i][j];
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[i][j] != '#') {
                bfs (i, j);

                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < m; jj++) {
                        if (ii == i && jj == j) continue;

                        if (str[ii][jj] != '#') {
                            mx = max (mx, dis[ii][jj]);
                        }
                    }
                }
            }
        }
    }

    cout << mx << "\n";
    return 0;
}
