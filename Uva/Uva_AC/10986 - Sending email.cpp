/***************************************************
 * Problem name : 10986 Sending  Mail.cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 11-04-17
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
#define MAX 20005
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
vector<int>cost[MAX];
int dis[MAX];
struct node {
    int u, w;
    node(int a, int b) {
        u = a;
        w = b;
    }
    bool operator < ( const node& p ) const{
        return w > p.w;
    }
};
int dijkstra(int s, int d) {
    priority_queue<node>Q;
    Q.push(node(s, 0));
    dis[s] = 0;
    while (!Q.empty()) {
        node top = Q.top();
        int u = top.u;
        Q.pop();
        int sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            int v = adj[u][i];
            int w = cost[u][i];
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                Q.push(node(v,dis[v]));
            }
        }
    }
    return dis[d];
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        dis[i] = 1000000;
    }
}
int main () {
    int tc, n, m, s, d;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d %d %d", &n, &m, &s, &d);
        if (m == 0) {
            printf("Case #%d: unreachable\n", t);
        } else {
            for (int i = 0; i < m; i++) {
                int u, v, w;
                scanf("%d %d %d", &u, &v, &w);
                adj[u].push_back(v);
                adj[v].push_back(u);
                cost[u].push_back(w);
                cost[v].push_back(w);
            }
            mem();
            int ans = dijkstra(s, d);
            if (ans == 1000000) {
                printf("Case #%d: unreachable\n", t);
            } else {
                printf("Case #%d: %d\n", t, dijkstra(s, d));
            }
        }
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

