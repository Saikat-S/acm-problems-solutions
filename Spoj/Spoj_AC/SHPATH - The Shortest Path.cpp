/***************************************************
 * Problem Name : SHPATH - The Shortest Path.cpp
 * Problem Link : https://www.spoj.com/problems/SHPATH/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-09-16
 * Problem Type : Graph (dijkstra)
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 10005
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
vector<int>adj[MAX], cost[MAX];
int dis[MAX];
struct node {
    int x, w;
    node (int a, int c) {
        x = a;
        w = c;
    }
};
bool operator < (node a, node b) {
    return a.w > b.w;
}
int dijkstra (int n, int s, int d) {
	for(int i = 1; i<=n; i++){
		dis[i] = 10000005;
	}
    priority_queue<node>Q;
    Q.push (node (s, 0) );
    dis[s] = 0;

    while (!Q.empty() ) {
        node top = Q.top();
        int u = top.x;
        Q.pop();
        int sz = adj[u].size();

        for (int i = 0; i < sz; i++) {
            int v = adj[u][i];
            int w = cost[u][i];

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                Q.push (node (v, dis[v]) );
            }
        }
    }
    return dis[d];
}
int main () {
    __FastIO;
    int tc, n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        map<string, int>mp;

        for (int i = 1; i <= n; i++) {
            string str;
            cin >> str;
            mp[str] = i;
            int p;
            cin >> p;

            for (int j = 1; j <= p; j++) {
                int v, w;
                cin >> v >> w;
                adj[i].pb (v);
                cost[i].pb (w);
            }
        }

        int Q;
        cin >> Q;

        for (int q = 1; q <= Q; q++) {
            string a, b;
            cin >> a >> b;
            int ans = dijkstra (n, mp[a], mp[b]);
            cout << ans << "\n";
        }
        
        for(int i = 0; i<MAX; i++){
			adj[i].clear();
			cost[i].clear();
		}
    }

    return 0;
}
