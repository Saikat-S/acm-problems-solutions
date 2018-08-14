#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#define pii pair<int, int>
#define MAX 705
using namespace std;
int n, m,timer;
vector<int>adj[MAX];
vector<pii>ans;
map<pii, bool>mp;
bool vis[MAX];
int dis[MAX], low[MAX];
bool cmp(pii a, pii b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}
void dfs(int u, int p){
    vis[u] = true;
    dis[u] = low[u] = timer++;
    for(int i = 0; i<(int)adj[u].size(); i++){
        int v = adj[u][i];
        if(v == p) continue;
        if(vis[v]){
            low[u] = min(low[u], dis[v]);
        }else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(dis[u] < low[v]){
                if(u > v && !mp[pii(v, u)]){
                    ans.push_back(pii(v, u));
                    mp[pii(v,u)] = true;
                }else if(!mp[pii(u, v)]){
                  ans.push_back(pii(u, v));
                  mp[pii(u,v)] = true;
                }
            }
        }
    }
}
void find_AP(){
    timer = 0;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(low, -1, sizeof(low));
    ans.clear();
    mp.clear();
    for(int i = 1; i<=n; i++) if(!vis[i]) dfs(i, -1);
    for(int i = 0; i<MAX; i++) adj[i].clear();
}
int main(){
   int tc;
   cin >> tc;
   for(int t =1; t<=tc; t++){
        cin >> n >> m;
        for(int i = 0; i<m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        find_AP();
        cout << "Caso #"<<t<<"\n";
        if((int)ans.size() == 0) cout << "Sin bloqueos\n";
        else{
            sort(ans.begin(), ans.end(), cmp);
            cout << (int)ans.size()<<"\n";
            for(int i = 0; i<(int)ans.size(); i++) cout << ans[i].first <<" " << ans[i].second<<"\n";
        }
   }
   return 0;
}
