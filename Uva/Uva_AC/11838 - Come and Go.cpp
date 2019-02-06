/***************************************************
 * Problem Name : 11838 - Come and Go.cpp
 * Problem Link : https://uva.onlinejudge.org/external/118/11838.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-10-25
 * Problem Type : Graph (dfs)
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
#define MAX 2005
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
bool vis[MAX];
int cnt;
void dfs (int u) {
    vis[u] = true;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (!vis[v]) {
            cnt++;
            dfs (v);
        }
    }
}
int main () {
    __FastIO;
    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;

            if (p == 1) {
                adj[u].pb (v);

            } else {
                adj[u].pb (v);
                adj[v].pb (u);
            }
        }

        bool flag = false;

        for (int i = 1; i <= n; i++) {
            SET (vis, false);
            cnt = 1;
            dfs (i);

            if (cnt != n) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "0\n";
        else cout << "1\n";

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
