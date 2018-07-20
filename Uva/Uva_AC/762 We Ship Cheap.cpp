/***************************************************
 * Problem name : 762 We Ship Cheap.cpp
 * Problem Link : https://uva.onlinejudge.org/external/7/762.pdf
 * OJ           : UVA
 * Verdict      : AC
 * Date         : 2017-12-01
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
map<string, ll>mp;
map<ll, string>mpp;
vector<ll>adj[MAX];
bool visit[MAX];
ll par[MAX], cost[MAX];
ll BFS(ll s, ll d) {
    queue<ll>Q;
    Q.push(s);
    cost[s] = 0;
    visit[s] = true;
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            ll v = adj[u][i];
            if (!visit[v]) {
                visit[v] = true;
                par[v] = u;
                cost[v] = cost[u] + 1;
                Q.push(v);
            }
        }
    }
    return cost[d];
}
int main () {
    ll n, t = 1;
    while (scanf("%lld", &n) == 1) {
        ll  k = 1;
        if (t != 1) nl;
        t++;
        for (int i = 1; i <= n; i++) {
            string u, v;
            cin >> u >> v;
            if (mp[u] == 0) {
                mp[u] = k++;
                mpp[mp[u]] = u;
            }
            if (mp[v] == 0) {
                mp[v] = k++;
                mpp[mp[v]] = v;
            }
            adj[mp[u]].push_back(mp[v]);
            adj[mp[v]].push_back(mp[u]);
        }
        string s, d;
        cin >> s >> d;
        if (mp[s] == 0 || mp[d] == 0) {
            printf("No route\n");
        } else {
            SET(par, 0);
            SET(visit, false);
            SET(cost, -1);
            ll chk = BFS(mp[s], mp[d]);
            if (chk == -1) {
                printf("No route\n");
            } else {
                vector<ll>path;
                path.push_back(mp[d]);
                for (int i = mp[d]; ;) {
                    path.push_back(par[i]);
                    if (par[i] == mp[s]) break;
                    i = par[i];
                }
                ll sz = path.size();
                for (int i = sz - 1; i >= 1; i--) {
                    cout << mpp[path[i]] << " " << mpp[path[i - 1]] << "\n";
                }
            }
        }
        mp.clear(), mpp.clear();
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
