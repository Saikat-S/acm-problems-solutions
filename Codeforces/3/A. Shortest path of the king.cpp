/***************************************************
 * Problem Name : A. Shortest path of the king.cpp
 * Problem Link : https://codeforces.com/contest/3/problem/A
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-01-23
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
#define FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
#define MAX 100005
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
#define pii pair<int,int>
int fx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int row, col;
void BFS_2d (int sx, int sy) {
    memset (vis, 0, sizeof (vis) );
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push (pii (sx, sy) );

    while (!q.empty() ) {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if (tx >= 0 && ty >= 0 && tx < row && ty < col && vis[tx][ty] == 0) {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push (pii (tx, ty) );
            }
        }
    }
}
int main () {
    //~ __FastIO;
    
    return 0;
}
