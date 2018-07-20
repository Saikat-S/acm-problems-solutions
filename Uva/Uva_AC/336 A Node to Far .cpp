/***************************************************
 * Problem name : 336 A Node to Far .cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 17-04-17
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
#define MAX 10000
#define pl printf("\n");
using namespace std;
typedef long long ll;
map<int, vector<int> >adj;
map<int, int>cost,visit;
int BFS(int s, int d) {
    int count = 0;
    queue<int>Q;
    Q.push(s);
    cost[s] = 0;
    visit[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            int v = adj[u][i];
            if(!visit[v]) {
                cost[v]  = cost[u] + 1;
                if (cost[v] > d) {
                    count++;
                }
                visit[v] = 1 ;
                Q.push(v);
            }
        }
    }
    return count;
}
void mem() {
    visit.clear();
    cost.clear();
}
int main () {
    int N, t = 1;
    while (scanf("%d", &N) == 1 && N != 0) {
        for (int i = 1; i <= N; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int s, d;
        while (scanf("%d %d", &s, &d) == 2 && (s != 0 || d != 0)) {
            int ans = BFS(s,d);
            ans += adj.size()-cost.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t++, ans, s, d);
            mem();
        }
        adj.clear();
    }
    return 0;
}

