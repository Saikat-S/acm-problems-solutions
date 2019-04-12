/***************************************************
 * Problem Name : F. Graph Without Long Directed Paths.cpp
 * Problem Link : https://codeforces.com/contest/1144/problem/F
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-01
 * Problem Type : Div 3 - F
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
#define MAX 200005
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
int color[MAX];
vector<pii>vec;
bool bfs (int s) {
    queue<int>Q;
    Q.push (s);
    color[s] = 1;

    while (!Q.empty() ) {
        int u = Q.front();
        Q.pop();

        for (int v : adj[u]) {
            if (color[v] == 0) {
                if (color[u] == 1) {
                    color[v] = 2;

                } else {
                    color[v] = 1;
                }

                Q.push (v);
            }

            if (color[u] == color[v]) {
                return false;
            }
        }
    }

    return true;
}
int main () {
    //~ __FastIO;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb (v);
        adj[v].pb (u);
        vec.pb (pii (u, v) );
    }

    SET (color, 0);
    bool flag = bfs (1);

    if (!flag) {
        cout << "NO\n";

    } else {
        cout << "YES\n";

        for (int i = 0; i < m; i++) {
            int u = vec[i].first;

            if (color[u] == 1) {
                cout << "1";

            } else {
                cout << "0";
            }
        }

        nl;
    }

    return 0;
}
