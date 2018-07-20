/***************************************************
 * Problem name : 11686 - Pick up sticks .cpp
 * OJ           : Uva
 * Result       : AC
 * Date         : 07-04-17
 * Problem Type : Graph
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define pii pair<int,int>
#define MAX 1000000
using namespace std;
typedef long long ll;
vector<ll>adj[MAX];
vector<ll>V;
int color[MAX], c;
void dfs(ll u) {
    if (c == 1) return;
    color[u] = 1;
    ll sz = adj[u].size();
    for (ll i = 0; i < sz; i++) {
        ll v = adj[u][i];
        if (color[v] == 1) {
			c = 1;
			return;
		}
        if (color[v] == 0) {
            dfs(v);
        }
    }
    color[u] = 2;
    V.push_back(u);
    return ;
}
void mem() {
    V.clear();
    for (ll i = 0; i < MAX; i++) {
        adj[i].clear();
        color[i] = 0;
    }
}
int main () {
    ll n, m;
    while (scanf("%lld %lld", &n, &m) == 2 && n != 0 && m != 0) {
        for (ll i = 1; i <= m; i++) {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            adj[u].push_back(v);
        }
        c = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                dfs(i);
            }
        }
        if (c == 1) {
            printf("IMPOSSIBLE\n");
        } else {
            for (int i = n - 1; i >= 0; i--) {
                printf("%lld\n", V[i]);
            }
        }
        mem();
    }
    return 0;
}
