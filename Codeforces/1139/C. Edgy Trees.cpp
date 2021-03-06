/***************************************************
 * Problem Name : C. Edgy Trees.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-03-21
 * Problem Type : Div 2 - C
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000000
#define MOD 1000000007
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
int n, k, cnt;
bool vis[MAX];
ll bigMod (ll n, ll b) {
    if (b == -1) b = MOD - 2;

    ll res = 1;

    while (b) {
        if (b & 1) res = (res * n) % MOD;

        n = (n * n) % MOD, b >>= 1;
    }

    return res;
}
void dfs (int u) {
    vis[u] = true;
    cnt++;

    for (int v : adj[u]) {
        if (vis[v] == false) {
            dfs (v);
        }
    }
}
int main () {
    __FastIO;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (w == 0) {
            adj[u].pb (v);
            adj[v].pb (u);
        }
    }

    ll ans = bigMod (n, k);
    SET (vis, false);

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            cnt = 0;
            dfs (i);
            ll x = bigMod (cnt, k);
            ans = ( (ans - x) + MOD) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}
