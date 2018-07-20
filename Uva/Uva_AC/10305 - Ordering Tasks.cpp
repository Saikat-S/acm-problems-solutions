/***************************************************
 * Problem name : 10305 - Ordering Tasks.cpp
 * OJ           : Uva
 * Result       : AC
 * Date         : 07-06-17
 * Problem Type : Topological Sort
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
vector<int>V;
int color[MAX];
void dfs(int u) {
    color[u] = 1;
    int sz = adj[u].size();
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (color[v] == 0) {
            dfs(v);
        }
    }
    V.push_back(u);
    return ;
}
void mem() {
    V.clear();
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
        color[i] = 0;
    }
}
int main () {
    int m, n;
    while (scanf("%d %d", &n, &m) == 2) {
		if(n == 0 && m == 0) break;
        if (m == 0) {
            for (int i = n; i >= 1; i--) {
                if (i ==  1) {
                    printf("%d\n",i);
                } else {
                    printf("%d ", i);
                }
            }
        } else {
            for (int i = 1; i <= m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                adj[u].push_back(v);
            }
            for (int i = 1; i <= n; i++) {
                if (color[i] == 0) {
                    dfs(i);
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (i ==  0) {
                    printf("%d\n", V[i]);
                } else {
                    printf("%d ", V[i]);
                }
            }
        }
        mem();
    }
    return 0;
}


