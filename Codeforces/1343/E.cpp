/***************************************************S
 * Problem Name : E.cpp
 * Problem Link : https://codeforces.com/contest/1343/problem/E
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-04-21
 * Problem Type : Div/Edu -
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <deque>
#include <stack>
#include <bitset>
#include <cassert>
#include <map>
#include <set>
#include <cassert>
#include <iomanip>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define __FileRead freopen ("input.txt", "r", stdin)
#define __FileWrite freopen ("output.txt", "w", stdout)
#define SET(a,v) memset(a,v,sizeof(a))
#define SZ(v) (int)v.size()
#define pii pair<int,int>
#define pil pair <int, ll>
#define pli pair <ll, int>
#define pll pair <ll, ll>
#define debug cout <<"######\n"
#define debug1(x) cout <<"### " << x << " ###\n"
#define debug2(x,y) cout <<"# " << x <<" : "<< y <<" #\n"
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define rall(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 200005
#define INF 1000000009
#define MOD 1000000007

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T>
using ordered_set  = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

template <typename T> string toString ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template<typename T> int toInt (T str) {
    stringstream ss;
    ss << str;
    int num;
    ss >> num;
    return num;
}
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
vector<vector<int>>adj;
vector<int>cost1, cost2, cost3;
vector<bool>vis;

void bfs (int s, int c) {
    queue<int>q;
    q.push (s);
    vis[s] = true;
    if(c == 1) cost1[s] = 0;
    if(c == 2) cost2[s] = 0;
    if(c == 3) cost3[s] = 0;

    while (!q.empty() ) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                if(c == 1)cost1[v] = cost1[u] + 1;
                if(c == 2)cost2[v] = cost2[u] + 1;
                if(c == 3)cost3[v] = cost3[u] + 1;
                q.push (v);
            }
        }
    }
}

void Clear (int n) {
    vis.clear();
    vis.resize (n, false);
}

int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        a--, b--, c--;
        adj.resize (n);
        vector<int>vec (m);

        for (int i = 0; i < m; i++) {
            cin >> vec[i];
            
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;

            adj[u].pb (v);
            adj[v].pb (u);
        }
        sort(all(vec));
        vector<ll>pre(m+1);
        for(int i = 0; i<m; i++){
			pre[i+1] = pre[i] + vec[i];
		}
        cost1.resize(n, INF),cost2.resize(n, INF), cost3.resize(n, INF);
        Clear(n);
        bfs(a, 1);
        Clear(n);
        bfs(b, 2);
        Clear(n);
        bfs(c, 3);
        
        ll res = 1e18;
        
        for(int i = 0; i<n; i++){
			if((cost1[i] + cost2[i] + cost3[i]) <= m){
				res = min(res, (ll)(pre[cost2[i]]) + pre[(cost1[i] + cost2[i] + cost3[i])]);
			}
		}
        
        
        cout << res << "\n";

        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
