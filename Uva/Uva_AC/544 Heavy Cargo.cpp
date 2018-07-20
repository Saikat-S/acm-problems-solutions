/***************************************************
 * Problem name : 544 Heavy Cargo.cpp
 * Problem Link : https://uva.onlinejudge.org/external/5/544.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-10-19
 * Problem Type : Graph(MST)
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
#define SET(a) memset(a,false,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 205
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
struct Edge {
    int u, v, w;
    bool operator<(const Edge &p) {
        return w > p.w;
    }
};
vector<Edge>E;
vector<int>adj[MAX], cost[MAX];
map<string, int>mp;
int par[MAX],M[MAX];
bool visit[MAX];
int find(int r) {
    if (par[r] == r) return r;
    else return par[r] = find(par[r]);
}
void MST(int n) {
    sort(E.begin(), E.end());
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    int sz = E.size(), s = 0;
    for (int i = 0; i < sz; i++) {
        int u = find(E[i].u);
        int v = find(E[i].v);
        if (u != v) {
            par[u] = v;
            adj[E[i].u].push_back(E[i].v);
            adj[E[i].v].push_back(E[i].u);
            cost[E[i].u].push_back(E[i].w);
            cost[E[i].v].push_back(E[i].w);
            //~ printf("%d %d %d\n", E[i].u , E[i].v, E[i].w);
            s++;
            if (s == n) return;
        }
    }
}
int bfs(int s, int d) {
    queue<int>Q;
    Q.push(s);
    visit[s] = true;
    M[s] = 1000000;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            int w = cost[u][i];
            if (visit[v] == false) {
                visit[v] = true;
                Q.push(v);
                M[v] = min(w, M[u]);
            }
        }
    }
    return M[d];
}
int main () {
    int n, r, t = 1;
    while (scanf("%d %d", &n, &r) == 2 && n != 0 && r != 0) {
        int k = 1;
        for (int i = 0; i < r; i++) {
            getchar();
            string u, v;
            int w;
            cin >> u >> v >> w;
            if (mp[u] == 0) mp[u] = k++;
            if (mp[v] == 0) mp[v] = k++;
            Edge get;
            get.u = mp[u], get.v = mp[v] , get.w = w;
            //~ printf("%d %d %d\n", get.u, get.v, get.w);
            E.push_back(get);
        }
        MST(n);
        getchar();
        string s, d;
        cin >> s >> d;
        SET(visit);
        for(int i = 0; i<MAX; i++){
            M[i] = -1;
        }
        int mx = bfs(mp[s], mp[d]);
        printf("Scenario #%d\n%d tons\n\n", t++, mx);
        E.clear(), mp.clear();
        for(int i = 0; i<MAX; i++){
            adj[i].clear();
            cost[i].clear();
            par[i] = 0;
        }
    }
    return 0;
}

