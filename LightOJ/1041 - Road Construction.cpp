/***************************************************
 * Problem name : 1041 - Road Construction.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1041                       
 * OJ           : LOJ                                  
 * Verdict      : AC                      
 * Date         : 2017-11-09                         
 * Problem Type : Graph(MST)                               
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU                     
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 200
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
struct edge {
    int u, v, w;
    bool operator<(const edge &p)const {
        return w < p.w;
    }
};
map<string, int>mp;
vector<int>adj[MAX];
int par[MAX], color[MAX];
vector<edge>e;
int find(int r) {
    if(par[r] == r) return r;
    else return par[r] = find(par[r]);
}
int MST(int n) {
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    int cnt = 0, s = 0, sz = e.size();
    for (int i = 0; i < sz; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            par[u] = v;
            cnt++;
            s += e[i].w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if (cnt == n - 1) break;
        }
    }
    return s;
}
void dfs(int u){
    color[u] = 1;
    int sz = adj[u].size();
    for(int i = 0; i<sz; i++){
        int v = adj[u][i];
        if(color[v] == 0){
            dfs(v);
        }
    }
}
void Clear(){
    for(int i = 0; i<MAX; i++){
        par[i] = 0;
        adj[i].clear();
    }
    e.clear(), mp.clear();
}
int main () {
    int tc, m;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &m);
        int k = 1;
        for (int i = 0; i < m; i++) {
            getchar();
            string u, v;
            int w;
            cin >> u >> v >> w;
            if(mp[u] == 0) mp[u] = k++;
            if(mp[v] == 0) mp[v] = k++;
            edge get;
            get.u = mp[u];
            get.v = mp[v];
            get.w = w;
            e.push_back(get);
        }
        int mx = MST(k);
        SET(color);
        dfs(1);
        bool flag = 0;
        for(int i = 1; i<k; i++){
            if(color[i] == 0){
                flag = 1;
                break;
            }
        }
        if(flag) printf("Case %d: Impossible\n", t);
        else printf("Case %d: %d\n",t, mx);
        Clear();
    }
    return 0;
}
