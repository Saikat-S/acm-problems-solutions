/***************************************************
 * Problem Name : D. Serval and Rooted Tree.cpp
 * Problem Link : https://codeforces.com/contest/1153/problem/D
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-04-18
 * Problem Type : Div 2 - D
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
vector<int>adj[MAX], leaf;
int val[MAX], k;
bool ar[MAX];

int dfs (int u, int p) {
    if ( (int) adj[u].size() == 0) {
        return k++;
    }

    int ans = 0;
    int mx = 0, mn = INF;

    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }

        int  tmp = dfs (v, u);

        if (ar[u] == 1) {
            mx = max (mx, tmp);

        } else {
            mn = min (mn, tmp);
        }
    }

    if (ar[u] == 1) {
        ans = mx;

    } else {
        ans = mn;
    }

    return ans;
}

int main () {
    //~ __FastIO;
    int n;
    cin >> n;

    for (int i = 1 ; i <= n; i++) {
        cin >> ar[i];
    }

    for (int i = 2; i <= n; i++) {	
        int x;
        cin >> x;
        adj[x].pb (i);
    }

    //~ for (int i = 2; i <= n; i++) {
    //~ if ( (int) adj[i].size() == 0) {
    //~ leaf.pb (i);
    //~ }
    //~ }
    k = 1;
    int ans = dfs (1, -1);
    cout << ans << "\n";
    return 0;
}

