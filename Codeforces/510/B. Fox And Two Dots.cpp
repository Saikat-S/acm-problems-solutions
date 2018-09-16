/***************************************************
 * Problem Name : B. Fox And Two Dots.cpp
 * Problem Link : http://codeforces.com/contest/510/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-08
 * Problem Type : Div 2 - B (BFS/DFS)
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
#define pb push_back
#define MAX 55
#define INF 1000000000
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
int vis[MAX][MAX], n, m;
string str[MAX];

bool bfs (int sx, int sy) {
    map<pii, pii>par;
    char ch = str[sx][sy];
    SET (vis, 0);
    vis[sx][sy] = true;
    queue <pii> q;
    q.push (pii (sx, sy) );

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (tx >= 0 && ty >= 0 && tx < n && ty < m && str[tx][ty] == ch) {
                if (vis[tx][ty] == true) {
                    if (par[top] != pii (tx, ty) ) return true;

                } else {
                    vis[tx][ty] = true;
                    q.push (pii (tx, ty) );
                    par[pii (tx, ty)] = top;
                }
            }
        }
    }

    return false;
}
int main () {
    __FastIO;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    int flag = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bfs (i, j) ) {
                flag = 1;
                break;
            }
        }

        if (flag) break;
    }

    if (flag) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

