//////////AC///////////
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<queue>
#define MAX 21
using namespace std;
//~ vector<int>V[MAX];
bool visit[MAX];
int cost[MAX];
int BFS(int s,int d, vector<int>V[]) {
    queue<int>Q;
    Q.push(s);
    cost[s] = 0;
    visit[s] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int sz = V[u].size();
        for(int i = 0; i<sz; i++) {
            int v = V[u][i];
            while(!visit[v]) {
                cost[v]  = cost[u] + 1;
                visit[v] = true ;
                Q.push(v);
            }
        }
    }
    return cost[d];
}
int main()
{
    int E;
    int t = 1;
    int i,x,j;
    while(scanf("%d", &E) != EOF) {
		vector<int>V[MAX];
        for(j = 1; j<=E; j++) {
            scanf("%d", &x);
            V[1].push_back(x);
            V[x].push_back(1);
        }
        for(i = 2; i<=19; i++) {
            scanf("%d", &E);
            for(j = 1; j<=E; j++) {
                scanf("%d", &x);
                V[i].push_back(x);
                V[x].push_back(i);
            }
        }
        int n;
        scanf("%d", &n);
        printf("Test Set #%d\n", t++);
        for(int l = 1; l<=n; l++) {
            int s,d;
            scanf("%d %d", &s, &d);
            memset(visit, false, sizeof visit);
            printf("%2d to %2d: %d\n",s,d,BFS(s,d,V));
        }
        printf("\n");
    }
    return 0;
}


