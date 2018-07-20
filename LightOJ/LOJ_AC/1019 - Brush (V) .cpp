/***************************************************
 * Problem name : 1019 - Brush (V) .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1019                       
 * OJ           : LOJ                                  
 * Verdict      : AC                      
 * Date         : 2017-11-30                         
 * Problem Type : Graph                               
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
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 105
#define INF 1000000000
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
vector<ll>adj[MAX], cost[MAX];
ll dist[MAX];
struct graph{
    ll u, w;
    graph(ll a, ll b){
        u = a;
        w = b;
    }
};
bool operator < (graph a, graph b){
    return a.w>b.w;
}
ll dijkstra(ll s, ll d){
    priority_queue<graph>Q;
    Q.push(graph(s, 0));
    dist[s] = 0;
    while(!Q.empty()){
        graph top = Q.top();
        ll u  = top.u;
        Q.pop();
        for(int i = 0; i<(int)adj[u].size(); i++){
            ll v = adj[u][i];
            ll w = cost[u][i];
            if((dist[u] + w )< dist[v]){
                dist[v] = dist[u] + w;
                Q.push(graph(v, dist[v]));
            }
        }
    }
    return dist[d];
}
void mem(){
    for(int i = 0; i<MAX; i++){
        dist[i] = 10000000;
    }
}
int main () {
    ll tc, N, M, x, y, d;
    scanf("%lld", &tc);
    for(int t = 1; t<=tc; t++){
        scanf("%lld %lld", &N, &M);
        for(int i = 0; i<M; i++){
            scanf("%lld %lld %lld", &x, &y, &d);
            adj[x].push_back(y);
            adj[y].push_back(x);
            cost[x].push_back(d);
            cost[y].push_back(d);
        }
       mem();
        ll ans = dijkstra(1, N);
        if(ans == 10000000){
            printf("Case %d: Impossible\n", t);
        }
        else {
            printf("Case %d: %lld\n", t, ans);
        }
        for(int i = 0; i<MAX; i++){
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
