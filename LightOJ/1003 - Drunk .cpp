/***************************************************
 * Problem name : 1003 - Drunk.cpp
 * OJ           : LOJ
 * Result       : AC
 * Date         : 00-03-17
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
#define MAX 10005
using namespace std;
typedef long long ll;
vector<int>adj[MAX];
vector<string>V;
map<string, int>mp;
int color[MAX];
int cycle;
void dfs(int u) {
	if(cycle == 1) return;
    color[u] = 1;
    int sz = adj[u].size();
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if(color[v] == 1){
			cycle = 1;
			return;
		}
        if (color[v] == 0) {
            dfs(v);
        }
    }
    color[u] = 2;
    return;
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
        color[i]  = 0;
    }
    mp.clear();
}
int main () {
    string str[MAX];
    int N,tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &N);
        for (int i = 1 ,k = 1; i <= N; i++) {
            string u,v;
            cin >>u >> v;
            if(mp[u] == 0){
				mp[u] = k++;
			}
			if(mp[v] == 0){
				mp[v] = k++;
			}
            adj[mp[u]].push_back(mp[v]);
        }
        cycle = 0;
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) {
                dfs(i);
            }
        }
        if(cycle){
			printf("Case %d: No\n",t);
		}
		else{
			printf("Case %d: Yes\n",t);
		}
        mem();
    }
    return 0;
}

