/***************************************************
 * Problem name : 1112 Mice and Maze.cpp
 * Problem Link : https://uva.onlinejudge.org/external/11/1112.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-09
 * Problem Type : Graph(dijkstra)
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
#define MAX 105
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
struct node {
    int u, w;
    node(int __u, int __w) {
        u = __u;
        w = __w;
    }
};
bool operator <(node a , node b) {
    return a.w > b.w;
}
vector<int>adj[MAX];
int cost[MAX][MAX], dis[MAX];
int dijkstra(int s, int d) {
    priority_queue<node>Q;
    dis[s] = 0;
    Q.push(node(s, dis[s]));
    while (!Q.empty()) {
        node top = Q.top();
        Q.pop();
        int u = top.u;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            int w = cost[u][v];
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                Q.push(node(v, dis[v]));
            }
        }
    }
    return dis[d];
}
void clear() {
    for (int i = 0; i <= MAX; i++) {
        dis[i] = 1000000;
    }
}
int main () {
    //~ __FastIO;
    int tc;
    int N, E, T, M;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d %d %d", &N, &E, &T, &M);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(v);
            cost[u][v] = w;
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            clear();
            int chk = dijkstra(i, E);
            if(chk<=T) cnt++;
        }
        printf("%d\n", cnt);
        if (t != tc) nl;
        SET(cost, 0);
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
