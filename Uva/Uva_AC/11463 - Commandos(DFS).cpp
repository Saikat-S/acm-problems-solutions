/***************************************************
 * Problem name : 11463 - Commandos(DFS).cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 17-04-17
 * Problem Type : Graph(DFS)
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
#define MAX 105
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
int cost[MAX], flag;
void dfs(int u) {
    if (flag == 0) {
        cost[u] = 0;
        flag = 1;
    }
    int sz = adj[u].size();
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (cost[u] + 1 < cost[v]) {
            cost[v] = cost[u] + 1;
            dfs(v);
        }
    }
    return ;
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        cost[i] = 1000000;
    }
}
int main() {
    int n, e, tc, sum;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        sum = 0;
        scanf("%d %d", &n, &e);
        for (int i = 1; i <= e; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int s, d;
        scanf("%d %d", &s, &d);
        flag = 0;
        mem();
        dfs(s);
        int max = 0, indx;
        for (int i = 0; i < n; i++) {
            if (max <= cost[i] && i != d) {
                max = cost[i];
                indx = i;
            }
        }
        int ar[MAX], cnt = 0;
        int a = cost[indx];
        for (int i = 0; i < n; i++) {
            if (a == cost[i] && i != d) {
                ar[cnt++] = i;
            }
        }
        max = 0;
        for (int i = 0 ; i < cnt; i++) {
            flag = 0;
            mem();
            dfs(ar[i]);
            if (max <= cost[d]) {
                max = cost[d];
            }
        }
        sum = a + max;
        printf("Case %d: %d\n", t, sum);
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
            cost[i] = 0;
        }
    }
    return 0;
}

