/***************************************************
 * Problem name : 1111 - Best Picnic Ever .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1111
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
#define MAX 1005
#define INF 1000000
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
vector<int>adj[MAX], Pe;
int color[MAX];
void dfs(int u){
    color[u] = 1;
    for(int i = 0; i<(int)adj[u].size(); i++){
        int v = adj[u][i];
        if(color[v] == 0) dfs(v);
    }
    return ;
}
int main () {
    int tc, K, N, M;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d %d", &K, &N, &M);
        for (int i = 1; i <= K; i++) {
            int x;
            scanf("%d", &x);
            Pe.push_back(x);
        }
        for (int i = 1; i <= M; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
        }
        int ans = INF, cnt;
        for (int i = 0; i < (int)Pe.size(); i++) {
            int s = Pe[i];
            SET(color, 0);
            dfs(s);
            cnt = 0;
            for(int n = 1; n<=N; n++){
                if(color[n] == 1) cnt++;
            }
            ans = min(ans, cnt);
        }
        printf("Case %d: %d\n", t, ans);
        Pe.clear();
        for(int i = 0;i<MAX; i++){
            adj[i].clear();
        }
    }
    return 0;
}
