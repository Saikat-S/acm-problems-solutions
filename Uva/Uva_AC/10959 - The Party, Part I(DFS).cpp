/***************************************************
 * Problem name : 10959 - The Party, Part I(DFS).cpp                       
 * OJ           : Uva                                  
 * Result       : AC                           
 * Date         : 18-04-17                          
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
#define MAX 1005
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
int cost[MAX],flag;
void dfs(int u) {
	if(flag == 0){
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
        cost[i] = 100000;
    }
}
void g_mem() {
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
    }
}
int main () {
    int P, D;
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d", &P, &D);
        for (int i = 1; i <= D; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        mem();
        flag = 0;
        dfs(0);
        for (int i = 1; i < P; i++) {
            printf("%d\n", cost[i]);
        }
        if (t != tc) {
            printf("\n");
        }
        g_mem();
    }
    return 0;
}

