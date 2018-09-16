/***************************************************
 * Problem name : E.cpp
 * OJ           : CF
 * Verdict      : AC
 * Date         : 2018-05-07
 * Problem Type : Div-3 E
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
#define MAX 200005
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
/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX];
int color[MAX],flag;
void dfs(int u) {
    color[u] = 1;
    int sz = adj[u].size();
    if(sz != 2){
        flag = 0;
    }
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if(color[v] == 0){
            dfs(v);
        }
    }
}
int main () {
    //~ __FastIO;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    SET(color, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            flag = 1;
            dfs(i);
            if(flag) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
