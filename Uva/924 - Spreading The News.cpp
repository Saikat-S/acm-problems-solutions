/***************************************************
 * Problem name : 924 - Spreading The News.cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 17-03-17
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
#define MAX 2505
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
int cost[MAX], visit[MAX], flag, ans;
int BFS(int s) {
    int mx = 0;
    queue<int>Q;
    visit[s] = 1;
    cost[s] = 0;
    Q.push(s);
    int count = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (cost[u] == flag) {
            flag = cost[u];
        } else {
            if (count > mx) {
                mx = count;
                ans = cost[u];
            }
            count = 0;
            flag++;
        }
        int sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            int v = adj[u][i];
            if (!visit[v]) {
                count++;
                visit[v] = 1;
                cost[v] = cost[u] + 1;
                Q.push(v);
            }

        }
    }
    return mx;
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        visit[i] = 0;
    }
}
int main () {
    int E;
    while (scanf("%d", &E) == 1) {
        for (int i = 0; i < E; i++) {
            int N;
            scanf("%d", &N);
            for (int j = 1; j <= N; j++) {
                int u;
                scanf("%d", &u);
                adj[i].push_back(u);
            }
        }
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int s;
            scanf("%d", &s);
            mem();
            flag = 0;
            int M = BFS(s);
            if (M == 0) {
                printf("0\n");
            } else {
                printf("%d %d\n", M, ans);
            }
        }
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }
    return 0;
}

