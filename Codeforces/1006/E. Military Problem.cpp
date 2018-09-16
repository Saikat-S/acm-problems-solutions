/***************************************************
 * Problem Name : E. Military Problem.cpp
 * Problem Link : http://codeforces.com/contest/1006/problem/E
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-20
 * Problem Type : Div 3 - E
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
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
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
vector<int>adj[MAX];
int start[MAX], endd[MAX];
int non[MAX];
int t = 0;
void dfs (int u) {
    t++;
    start[u] = t;
    non[t] = u;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];
        dfs (v);
    }

    endd[u] = t;
}
int main () {
    __FastIO;
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].pb (i);
    }

    dfs (1);

    for (int i = 0; i < q; i++) {
        int u, k;
        cin >> u >> k;
        int x = start[u] + k - 1;

        if (x > endd[u]) {
            cout << "-1\n";

        } else cout << non[x] << "\n";
    }

    return 0;
}
