/***************************************************
 * Problem Name : 796 - Critical Links.cpp
 * Problem Link : https://uva.onlinejudge.org/external/7/796.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-08-09
 * Problem Type : Graph (Find Bridge)
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX];
vector<pii>ans;
int n, t;
bool vis[MAX];
map<pii, bool>mp;
int dis[MAX], low[MAX];
void dfs (int u, int p) {
    vis[u] = true;
    low[u] = dis[u] = t++;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v  = adj[u][i];

        if (v == p) continue;

        if (vis[v] == true) {
            low[u] = min (low[u], dis[v]);

        } else {
            dfs (v, u);
            low[u] = min (low[u], low[v]);

            if (dis[u] < low[v]) {
                if (u > v) {
                    if (mp[pii (v, u)] == 0) {
                        ans.pb (pii (v, u) );
                        mp[pii (v, u)] = 1;
                    }

                } else {
                    if (mp[pii (u, v)] == 0) {
                        ans.pb (pii (u, v) );
                        mp[pii (u, v)] = 1;
                    }
                }
            }
        }
    }
}
void find_bridge() {
    t = 0;
    SET (vis, false);
    SET (dis, -1);
    SET (low, -1);
    mp.clear();

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs (i, -1);
    }
}
int main () {
    //~ __FastIO;
    while (cin >> n) {
        if (n == 0) {
            cout << "0 critical links\n";
            nl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            int u;
            string str;
            cin >> u >> str;
            int num = 0;

            for (int j = 1; j < (int) str.size() - 1; j++) {
                num = (num * 10) + (str[j] - '0');
            }

            for (int j = 0; j < num; j++) {
                int v;
                cin >> v;
                adj[u].pb (v);
                adj[v].pb (u);
            }
        }

        find_bridge();
        cout << (int) ans.size() << " critical links\n";
        sort (all (ans) );

        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i].first << " - " << ans[i].second << "\n";
        }

        nl;
        ans.clear();
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
