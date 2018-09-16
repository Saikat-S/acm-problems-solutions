/***************************************************
 * Problem Name : B. Mr. Kitayuta's Colorful Graph.cpp
 * Problem Link : http://codeforces.com/contest/505/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-11
 * Problem Type : Div 2 - B (Graph- BFS)
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
#define MAX 105
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
vector<int>adj[MAX], color[MAX];
bool vis[MAX];
bool bfs (int s, int d, int c) {
    SET (vis, 0);
    queue<int>Q;
    Q.push (s);
    vis[s] = true;

    while (!Q.empty() ) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            int cc = color[u][i];

            if (!vis[v] && cc == c) {
                vis[v] = true;

                if (v == d) return 1;

                Q.push (v);
            }
        }
    }

    return 0;
}
int main () {
    __FastIO;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb (v);
        adj[v].pb (u);
        color[u].pb (c);
        color[v].pb (c);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int s, d;
        cin >> s >> d;
        int cnt = 0;

        for (int c = 1; c <= m; c++) {
            if (bfs (s, d, c) ) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
