/********************************************
 * Problem name : 10004 - Bicoloring (Use DFS)
 * OJ           : UVA
 * Result       : Accepted
 * Date         : 17-04-17
 * Problem Type : Graph(DFS)
 ********************************************/
#include<iostream>
#include<cstdio>
#include<vector>
#define MAX 205
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
int color[MAX], flag;       // green = 1, red = 2;
void dfs(int u) {
	if(flag == 1)return ;
    if (color[u] == 0) {
        color[u] = 1;
    }
    int sz = adj[u].size();
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (color[v] == 0) {
            if (color[u] == 1) {
                color[v] = 2;
                dfs(v);
            } else {
                dfs(v);
            }
        }
        if(color[u] == color[v]){
			flag = 1;
			return ;
		}
    }
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        color[i] = 0;
        adj[i].clear();
    }
}
int main () {
    int N, E;
    while (scanf("%d", &N) == 1 && N != 0) {
        scanf("%d", &E);
        for (int i = 0; i < E; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        flag = 0;
        dfs(0);
        if (flag == 1) {
            printf("NOT BICOLORABLE.\n");
        } else {
            printf("BICOLORABLE.\n");
        }
        mem();
    }
    return 0;
}
