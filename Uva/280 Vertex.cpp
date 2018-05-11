/***************************************************
 * Problem name : 280 Vertex.cpp
 * Problem Link : https://uva.onlinejudge.org/external/2/280.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-10-19
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
#define SET(a) memset(a,false,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 105
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
bool color[MAX];
void dfs(int u){
    //color[u] = true;
    int sz = adj[u].size();
    for(int i = 0; i<sz; i++){
        int v = adj[u][i];
        if(color[v]== false){
            color[v] = true;
            dfs(v);
        }
    }
}
int main () {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int u, v;
        while(scanf("%d", &u) == 1 && u!=0){
            while(scanf("%d", &v) == 1 && v!=0){
                adj[u].push_back(v);
            }
        }
        //~ printf("fbkf\n");
        int N,s;
        scanf("%d", &N);
        for(int i = 0; i<N; i++){
            scanf("%d", &s);
            SET(color);
            dfs(s);
            int cnt = 0;
            vector<int>V;
            for(int j = 1; j<=n; j++){
                if(color[j] == false){
                    cnt++;
                    V.push_back(j);
                }
            }
            printf("%d", cnt);
            for(int k = 0; k<(int)V.size(); k++){
                printf(" %d", V[k]);
            }
            nl;
        }
        for(int i = 0; i<MAX; i++){
            adj[i].clear();
        }
    }
    return 0;
}
