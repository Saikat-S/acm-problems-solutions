/***************************************************
 * Problem Name : 247 Calling Circles.cpp
 * Problem Link : https://uva.onlinejudge.org/external/2/247.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-10-26
 * Problem Type : Graph (SCC)
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
#define MAX 30
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
vector<int>adj[MAX], adjR[MAX], order, component;
bool vis[MAX];
void dfs (int u) {
    vis[u] = true;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (!vis[v]) dfs (v);
    }

    order.pb (u);
}
void dfs1 (int u) {
    vis[u] = true;
    component.pb (u);

    for (int i = 0; i < (int) adjR[u].size(); i++) {
        int v = adjR[u][i];

        if (!vis[v]) dfs1 (v);
    }
}
int main () {
    __FastIO;
    int n, m, t = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        map<string, int>mp;
        map<int, string>mpS;
        int k = 1;

        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;

            if (mp[a] == 0) {
                mp[a] = k++;
                mpS[mp[a]] = a;
            }

            if (mp[b] == 0) {
                mp[b] = k++;
                mpS[mp[b]] = b;
            }

            adj[mp[a]].pb (mp[b]);
            adjR[mp[b]].pb (mp[a]);
        }

        SET (vis, false);
        order.clear();

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs (i);
        }

        SET (vis, false);

        if (t != 1) cout << "\n";

        cout << "Calling circles for data set " << t++ << ":\n";

        for (int i = 1; i <= n; i++) {
            int v = order[n - i];

            if (!vis[v]) {
                dfs1 (v);

                for (int j = 0; j < (int) component.size(); j++) {
                    cout << mpS[component[j]];

                    if (j != (int) component.size() - 1) cout << ", ";
                }

                nl;
                component.clear();
            }
        }

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            adjR[i].clear();
        }
    }

    return 0;
}
