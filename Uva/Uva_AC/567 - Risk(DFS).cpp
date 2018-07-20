/***************************************************
 * Problem name : 567 - Risk(DFS).cpp
 * OJ           : Uva
 * Result       : Accepted
 * Date         : 17-4-17
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
#define MAX 22
using namespace std;
vector<int>adj[MAX];
int cost[MAX],flag;
void dfs(int u) {
	if(flag == 0){
		cost[u] = 0;
		flag = 1;
	}
	int sz = adj[u].size();
	for(int i = 0; i<sz; i++){
		int v = adj[u][i];
		if(cost[u]+1<cost[v]){
			cost[v] = cost[u] + 1;
			dfs(v);
		}
	} 
}
void mem(){
	for(int i = 0; i<MAX; i++){
		cost[i] = 100000;
	}
}
int main()
{
    int E;
    int t = 1;
    int i,x,j;
    while(scanf("%d", &E) != EOF) {
        for(j = 1; j<=E; j++) {
            scanf("%d", &x);
            adj[1].push_back(x);
            adj[x].push_back(1);
        }
        for(i = 2; i<=19; i++) {
            scanf("%d", &E);
            for(j = 1; j<=E; j++) {
                scanf("%d", &x);
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        int n;
        scanf("%d", &n);
        printf("Test Set #%d\n", t++);
        for(int l = 1; l<=n; l++) {
            int s,d;
            scanf("%d %d", &s, &d);
            mem();
            flag = 0;
            dfs(s);
            printf("%2d to %2d: %d\n",s,d,cost[d]);
        }
        printf("\n");
        for(int i = 0; i<MAX; i++){
			adj[i].clear();
		}
    }
    return 0;
}
