/***************************************************
 * Problem Name : F. Asya And Kittens.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-02-24
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
#define MAX 150005
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
vector<int>adj[MAX], adj1[MAX], ans;
int child[MAX];
void dfs1 (int u, int p) {
    //~ if ( (int) adj[u].size() == 0 && p !=-1) return 1;
    //~ int cnt = 0;
    child[u] = 1;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        dfs1 (v, u);
        child[u] += child[v];
    }

    //~ return child[u] = cnt;
}
void dfs (int u, int p) {
    ans.pb (u);

    for (int i = 0; i < (int) adj1[u].size(); i++) {
        int v = adj1[u][i];

        if (v == p) continue;

        dfs (v, u);
    }
}
int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    vector<pii>vec;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        //~ adj[x].pb (y);
        adj[y].pb (x);
        adj1[x].pb (y);
        adj1[y].pb (x);
        vec.pb (pii (x, y) );
    }

    int u;
    //~ vector<int>nod;

    for (int i = 1; i <= n; i++) {
        if ( (int) adj[i].size() == 1) {
            u = i;
            //~ nod.pb (i);
            break;
        }
    }

    //~ int mx = 0;
    //~ for (int i = 0; i < (int) nod.size(); i++) {
    //~ SET (child, 0);
    //~ int v = nod[i];
    //~ dfs1 (v, -1);
    //~ int x = child[v];
    //~ if (x > mx) {
    //~ u = v;
    //~ mx = x;
    //~ }
    //~ }
    //~ nl;
    //~ debug;
    //~ cout << u << " -\n";
    dfs (u, -1);

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }

    nl;
    return 0;
}
