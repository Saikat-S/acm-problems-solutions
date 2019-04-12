/***************************************************
 * Problem Name : 1034 - Hit the Light Switches.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1034
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-10-26
 * Problem Type : graph
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
vector<int> adj[MAX];
bool vis[MAX];
vector<int> ans;
//~ int cnt;
void dfs1 (int u) {
    vis[u] = true;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (!vis[v]) {
            dfs1 (v);
        }
    }
}


void dfs (int u) {
    vis[u] = true;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (!vis[v])
            dfs (v);
    }

    ans.push_back (u);
}

void top_sort (int n) {
    SET (vis, false);
    ans.clear();

    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs (i);
    }

    reverse (ans.begin(), ans.end() );
}
int main () {
    //~ __FastIO;
    int tc, n, m;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf ("%d %d", &u, &v);
            adj[u].pb (v);
        }

        top_sort (n);
        int cnt = 0;
        SET (vis, false);

        for (int i = 0; i < (int) ans.size(); i++) {
            int v = ans[i];

            if (!vis[v]) {
                cnt++;
                dfs1 (v);
            }
        }

        printf ("Case %d: %d\n", t, cnt);

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
