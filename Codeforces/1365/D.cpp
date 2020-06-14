/***************************************************
 * Problem Name : D.cpp
 * Problem Link : https://codeforces.com/contest/1365/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-06-07
 * Problem Type : Div/Edu -
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
#define MAX 55
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
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
char mat[MAX][MAX];
int n, m;

bool vis[MAX][MAX];
bool isV (int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) return 1;

    return 0;
}

void bfs (int sx, int sy) {
    SET (vis, 0);
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push (pii (sx, sy) );

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (isV (tx, ty) && vis[tx][ty] == 0 && (mat[tx][ty] == '.'
                    || mat[tx][ty] == 'G') ) {
                vis[tx][ty] = 1;
                q.push (pii (tx, ty) );
            }
        }
    }
}
void bfs1 (int sx, int sy) {
    SET (vis, 0);
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push (pii (sx, sy) );

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (isV (tx, ty) && vis[tx][ty] == 0 && (mat[tx][ty] == '.'
                    || mat[tx][ty] == 'G' || mat[tx][ty] == 'B') ) {
                vis[tx][ty] = 1;
                q.push (pii (tx, ty) );
            }
        }
    }
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        vector<pii>vec, gg;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];

                if (mat[i][j] == 'B') vec.pb ({i, j});
                else if (mat[i][j] == 'G') gg.pb ({i, j});
            }
        }

        if ( (int) gg.size() == 0) {
            cout << "Yes\n";

        } else {
            bool f = 0;

            for (int i = 0; i < (int) vec.size(); i++) {
                int x = vec[i].F;
                int y = vec[i].S;

                for (int k = 0; k < 4; k++) {
                    int xx = x + fx[k];
                    int yy = y + fy[k];

                    if (isV (xx, yy) ) {
                        if (xx == n - 1 && yy == m - 1) continue;

                        if (mat[xx][yy] == 'G') {
                            f = 1;
                            break;

                        } else if (mat[xx][yy] == '.') {
                            mat[xx][yy] = '#';
                        }
                    }
                }
            }

            if (f) cout << "No\n";
            else {
                bfs1 (n - 1, m - 1);

                for (int i = 0; i < (int) vec.size(); i++) {
                    int x = vec[i].F;
                    int y = vec[i].S;

                    if (vis[x][y] == 1) {
                        f = 1;
                        break;
                    }
                }

                if (f) cout << "No\n";
                else {
                    bfs (n - 1, m - 1);

                    for (int i = 0; i < (int) gg.size(); i++) {
                        int x = gg[i].F;
                        int y = gg[i].S;

                        if (vis[x][y] == 0) {
                            f = 1;
                            break;
                        }
                    }

                    if (f) cout << "No\n";
                    else cout << "Yes\n";
                }
            }
        }
    }

    return 0;
}
