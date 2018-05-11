/***************************************************
 * Problem name : 1094 - Farthest Nodes in a Tree .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1094
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-08-07
 * Problem Type : Graph(BFS)
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
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 30003
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
vector<int>adj[MAX], W[MAX];
ll dis[MAX];
bool visit[MAX];
void bfs(int s) {
    queue<int>Q;
    visit[s] = true;
    dis[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            int v = adj[u][i];
            int w = W[u][i];
            if (visit[v] == false) {
                dis[v] = dis[u] + w;
                visit[v] = true;
                Q.push(v);
            }
        }
    }
}
void mem(){
    for(int i = 0; i<MAX; i++){
        visit[i] = false;
        dis[i] = 0;
    }
}
void Clear(){
    for(int i = 0; i<MAX; i++){
        adj[i].clear();
        W[i].clear();
    }
}

int main () {
    int tc, n;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }
        int s = 0;
        mem();
        bfs(s);
        for (int i = 0; i < n; i++) {
            if (dis[s] < dis[i]) s = i;
            //~ printf("%lld\n", dis[i]);
        }
        ll mx = 0;
        mem();
        bfs(s);
        for (int i = 0; i < n; i++) {
            mx = max(mx, dis[i]);
        }
        printf("Case %d: %lld\n", t, mx);
        Clear();
    }
    return 0;
}

