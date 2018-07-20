/***************************************************
 * Problem name : 6825 Even distribution.cpp
 * Problem Link : https://icpcarchive.ecs.baylor.edu/external/68/6825.pdf                        
 * OJ           : UvaLive                                  
 * Verdict      : AC                     
 * Date         : 2018-05-05                         
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
#define MAX 100005
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
vector<int>adj[MAX];
int P[MAX];
map<pii, bool>vis;
set<int>st;
void bfs(queue<pii>Q) {
    while (!Q.empty()) {
        pii top = Q.front();
        int u = top.first;
        int gc = top.second;
        Q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            int gcc  = gcd(gc, P[v]);
            if (vis[make_pair(v,gcc)] == false) {
                vis[make_pair(v,gcc)] = true;
                //~ gc = gcd(gc, P[v]);
                Q.push(make_pair(v,gcc));
                st.insert(gcc);
            }
        }
    }
}

int main () {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        queue<pii>Q;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &P[i]);
            Q.push(make_pair(i, P[i]));
            vis[make_pair(i, P[i])] == true;
            st.insert(P[i]);
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bfs(Q);
        printf("%d\n", (int)st.size());
        vis.clear();
        st.clear();
        for(int i = 0; i<MAX; i++){
            adj[i].clear();
        }
    }
    return 0;
}
