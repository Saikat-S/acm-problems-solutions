/***************************************************
 * Problem Name : F1. Tree Cutting (Easy Version).cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-02-20
 * Problem Type :
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
#define MAX 300005
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
int ar[MAX], col1[MAX][3], blue = 0, red = 0;
int col[MAX][3];
bool vis[MAX];
pii dfs (int u, int p) {
    vis[u] = true;

    if ( (int) adj[u].size() == 1 && p != -1) {
        return pii (col[u][1], col[u][2]);
    }

    pii top;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        if (vis[v] == false) {
            pii tmp = dfs (v, u);
            top.first += tmp.first;
            top.second += tmp.second;
        }
    }

    col[u][1] += top.first;
    col[u][2] += top.second;
    return pii (col[u][1], col[u][2]);
}
int cnt = 0;
void dfs1 (int u, int p) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if ( v == p) continue;

        int rd = col[v][1];
        int bl = col[v][2];

        if ( (rd == red && bl == 0) || (bl == blue && rd == 0) ) cnt++;

        dfs1 (v, u);
    }
}
int main () {
    //~ __FastIO;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        col[i][ar[i]]++;

        if (ar[i] == 1) red++;

        if (ar[i] == 2) blue++;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    SET (vis, false);
    dfs (1, -1);
    dfs1 (1, -1);
    cout << cnt << "\n";
    return 0;
}
