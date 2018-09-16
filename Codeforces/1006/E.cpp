/***************************************************
 * Problem Name : E.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-07-16
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
#define MAX 200005
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
vector<int>path;
//~ int vis[MAX];
int non[MAX];
//~ int t = 0;
void dfs (int u, int p) {
    path.pb (u);
    //~ vis[u] = 1;
    non[u] = 1;

    //~ t++;
    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];
        //~ if (vis[v] == 0) dfs (v);
        dfs (v, u);
        non[u] += non[v];
    }

    //~ non[u] = t;
}
//~ void numberOfNodes (int u, int p) {
//~ non[u] = 1;

//~ for (int i = 0; i < (int) adj[u].size(); i++) {
//~ int v = adj[u][i];

//~ if (v == p)
//~ continue;

//~ numberOfNodes (v, u);
//~ non[u] += non[v];
//~ }
//~ }
int main () {
    //~ __FastIO;
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].pb (i);
        //~ adj[i].pb (x);
    }

    //~ SET (vis, 0);
    dfs (1, 0);
    //~ numberOfNodes (1,  0);

    for (int i = 0; i < q; i++) {
        int u, k;
        cin >> u >> k;

        if (non[u] < k) {
            cout << "-1\n";

        } else {
            int lw = lower_bound (all (path), u) - path.begin();
            int id = lw + k - 1;
            cout << path[id] << "\n";
        }
    }

    return 0;
}
