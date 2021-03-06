/***************************************************
 * Problem Name : D.cpp
 * Problem Link : https://codeforces.com/contest/1345/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-05-03
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
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
vector<vector<char>>vec;

bool vis[MAX][MAX];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int n, m;


void dfs (int sx, int sy) {
    vis[sx][sy] = true;

    for (int i = 0; i < 4; i++) {
        int x = fx[i] + sx;
        int y = fy[i] + sy;

        if (x >= 0 && x < n && y >= 0 && y < m && vec[x][y] == '#' && !vis[x][y]) {
            dfs (x, y);
        }
    }
}


int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    cin >> n >> m;
    vector<vector<char>>vv (n, vector<char> (m) );
    vec = vv;
    int cc = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];

            if (vec[i][j] == '#') cc++;
        }
    }

    bool flag = false;
    int row = 0, col = 0;

    for (int i = 0; i < n; i++) {
        int f = 0;
        int c = 0;

        for (int j = 0; j < m; j++) {
            if (f == 2 && vec[i][j] == '#') flag = true;

            if (vec[i][j] == '#') {
                f = 1;
                c = 1;
            }

            if (f == 1 && vec[i][j] == '.') f = 2;
        }

        if (!c) {
            row++;
        }
    }

    for (int j = 0; j < m; j++) {
        int f = 0;
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (f == 2 && vec[i][j] == '#') flag = true;

            if (vec[i][j] == '#') {
                f = 1;
                c = 1;
            }

            if (f == 1 && vec[i][j] == '.') f = 2;
        }

        if (!c) {
            col++;
        }
    }

    if (flag || (max (col, row) != 0 && min (col, row) == 0) ) {
        cout << "-1\n";

    } else {
        SET (vis, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vec[i][j] == '#' && !vis[i][j]) {
                    cnt++;
                    dfs (i, j);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
