/***************************************************
 * Problem Name : C. Connect.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-02-24
 * Problem Type :
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 55
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int n;
int sr, sc, dr, dc;
char str[MAX][MAX];
bool vis[MAX][MAX];
bool vis1[MAX][MAX];

int fun1 (int sx, int sy, int dx, int dy) {
    //~ int mn = INF;
    SET (vis1, false);
    vis[sx][sy] = true;
    queue <pii> q;
    q.push (pii (sx, sy) );
    int mn = Pow2 (dx - sx) + Pow2 (dy - sy);

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (tx >= 0 && ty >= 0 && tx < n && ty < n && str[tx][ty] == '0'
                && vis1[tx][ty] == false) {
                vis1[tx][ty] = true;
                int tmp = Pow2 (dx - tx) + Pow2 (dy - ty);
                mn = min (mn, tmp);
                q.push (pii (tx, ty) );
            }
        }
    }

    return mn;
}
int fun (int sx, int sy) {
    SET (vis, false);
    vis[sx][sy] = true;
    queue <pii> q;
    q.push (pii (sx, sy) );
    int mn = fun1 (dr, dc, sx, sy);

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (tx >= 0 && ty >= 0 && tx < n && ty < n && str[tx][ty] == '0'
                && vis[tx][ty] == false) {
                vis[tx][ty] = true;
                q.push (pii (tx, ty) );
                int tmp = fun1 (dr, dc, tx, ty);
                mn = min (mn, tmp);
            }
        }
    }

    return mn;
}
int main () {
    //~ __FastIO;
    cin >> n;
    cin >> sr >> sc;
    cin >> dr >> dc;
    sr--, sc--;
    dr--, dc--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> str[i][j];
        }
    }

    int ans = fun (sr, sc);
    cout << ans << "\n";
    return 0;
}
