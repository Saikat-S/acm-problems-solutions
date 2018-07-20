/***************************************************
 * Problem name : 1009 - Back to Underworld .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1009
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
int color[MAX];
int V, W;
void biColoring(int s) {
    queue<int>Q;
    Q.push(s);
    color[s] = 1;
    V++;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if (color[v] == 0) {
                if (color[u] == 1) {
                    color[v] = 2;
                    W++;
                }
                else {
                    color[v] = 1;
                    V++;
                }
                Q.push(v);
            }
        }
    }
}
int main () {
    int tc, N;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &N);
        map<int, int>mp;
        vector<int>G;
        for (int i = 1; i <= N; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            if (mp[u] == 0) {
                G.push_back(u);
                mp[u] = 1;
            }
            if (mp[v] == 0) {
                G.push_back(v);
                mp[v] = 1;
            }
        }
        SET(color, 0);
        int ans = 0;
        for (int i = 0; i < (int)G.size();) {
            int s = G[i];
            if (color[s] == 0) {
                V = 0, W = 0;
                biColoring(s);
                ans += max(V,W);
            } 
            else i++;
        }
        printf("Case %d: %d\n", t, ans);
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
