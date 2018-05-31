/***************************************************
 * Problem Name : Fire Escape Routes.cpp
 * Problem Link : https://www.codechef.com/problems/FIRESC
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-05-31
 * Problem Type : Graph (dfs)
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}

/************************************ Code Start Here ******************************************************/
ll MOD = 1e9 + 7;

vector<int>G[MAX];
int vis[MAX];
ll cnt;
void dfs (int u) {
    cnt++;
    vis[u] = 1;

    for (int i = 0; i < (int) G[u].size(); i++) {
        int v = G[u][i];

        if (!vis[v]) {
            dfs (v);
        }
    }
}
int main () {
    //~ __FastIO;
    int TC;
    scanf ("%d", &TC);

    while (TC--) {
        memset (vis, 0, sizeof (vis) );
        int N, M;
        scanf ("%d %d", &N, &M);

        for (int i = 0; i < M; i++) {
            int u, v;
            scanf ("%d %d", &u, &v);
            G[u].pb (v);
            G[v].pb (u);
        }

        ll ans1 = 0;
        ll ans2 = 1LL;

        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                ans1++;
                cnt = 0LL;
                dfs (i);
                ans2 = (ans2 * cnt) % MOD;
            }
        }

        printf ("%lld %lld\n", ans1, ans2);

        for (int i = 0; i <= N; i++) G[i].clear();
    }

    return 0;
}
