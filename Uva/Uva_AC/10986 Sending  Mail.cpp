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
map<pii, int>mp;
//~ int cost[MAX][MAX];
int dis[MAX];
int dijkstra(int s, int d) {
    //~ priority_queue<int>Q;
    queue<int>Q;
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            int v = adj[u][i];
            pii p = make_pair(u, v);
            if (dis[u] + mp[p] < dis[v]) {
                dis[v] = dis[u] + mp[p];
                Q.push(v);
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
                pii p = make_pair(u, v);
                mp[p] = w;
                pii q = make_pair(v, u);
                mp[q] = w;
                //~ cost[u][v] = w;
                //~ cost[v][u] = w;
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
            //~ for(int j = 0; j<MAX; j++){
            //~ cost[i][j] = 0;
            //~ }
        }
        mp.clear();
    }
    return 0;
}

