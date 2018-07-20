/***************************************************
 * Problem name : 10116 Robot Motion.cpp
 * Problem Link : https://uva.onlinejudge.org/external/101/10116.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-10
 * Problem Type : Graph
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 13
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
string str[MAX];
map<pii, pii>mp;
int row, col, vis[MAX][MAX], d[MAX][MAX];
int x, y, flag, n;
void move(char ch) {
    if (ch == 'N') {
        x--;
    } else if (ch == 'S') {
        x++;
    } else if (ch == 'E') {
        y++;
    } else {
        y--;
    }
}
bool isValid(int tx, int ty) {
    if (tx >= 0 && ty >= 0 && tx < row && ty < col) return true;
    return false;
}
int BFS_2d(int sx, int sy) {
    SET(vis, 0);
    SET(d, 0);
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    d[sx][sy] = 1;
    queue <pii> q;
    q.push(pii(sx, sy));
    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        int tx = top.first;
        int ty = top.second;
        x = tx, y = ty;
        move(str[tx][ty]);
        if (isValid(x, y)) {
            if (vis[x][y] == 0) {
                mp[pii(x, y)] = top;
                vis[x][y] = 1;
                d[x][y] = d[top.first][top.second] + 1;
                q.push(pii(x, y));
            } else {
                pii p = mp[pii(x, y)];
                int xx = p.first;
                int yy = p.second;
                flag = 1;
                if (x == sx && y == sy) {
                    n = d[top.first][top.second];
                    return d[top.first][top.second];
                } else {
                    n = d[top.first][top.second];
                    return d[top.first][top.second] - d[xx][yy];
                }
            }
        } else {
            return d[top.first][top.second];
        }
    }
}
int main () {
    //~ __FastIO;
    int pos;
    while (scanf("%d %d %d", &row, &col, &pos) == 3 && row != 0 && col != 0 && pos != 0) {
        for (int i = 0; i < row; i++) {
            cin >> str[i];
        }
        flag = 0;
        int ans = BFS_2d(0, pos - 1);
        if (flag) {
            int a = n - ans;
            printf("%d step(s) before a loop of %d step(s)\n", a, ans);
        } else {
            printf("%d step(s) to exit\n", ans);
        }

        mp.clear();
    }
    return 0;
}
