/***************************************************
 * Problem Name : SUBMERGE - Submerging Islands.cpp
 * Problem Link : https://www.spoj.com/problems/SUBMERGE/
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-08-11
 * Problem Type : Graph ( AP )
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 10005
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
vector<int>adj[MAX];
int n, m, t, cnt;
int dis[MAX], low[MAX];
bool vis[MAX], chk[MAX];
void dfs (int u, int p) {
    vis[u] = true;
    dis[u] = low[u] = t++;
    int child = 0;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        if (vis[v]) {
            low[u] = min (low[u], dis[v]);

        } else {
            dfs (v, u);
            low[u] = min (low[u], low[v]);

            if (dis[u] <= low[v] && p != -1 && !chk[u]) {
                cnt++;
                chk[u] = true;
            }

            child++;
        }
    }

    if (p == -1 &&  child > 1 && !chk[u]) cnt++;
}
void find_articulation_point() {
    cnt = t = 0;
    SET (vis, false);
    SET (chk, false);
    SET (dis, -1);
    SET (low, -1);

    for (int i = 1; i <= n; i++) if (!vis[i]) dfs (i, -1);

    for (int i = 0; i < MAX; i++) adj[i].clear();
}
int main () {
    __FastIO;

    while (cin >> n >> m) {
        if (n == m &&  m  == 0) break;

        for (int i = 0; i < m ; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].pb (b);
            adj[b].pb (a);
        }

        find_articulation_point();
        cout << cnt << "\n";
    }

    return 0;
}
