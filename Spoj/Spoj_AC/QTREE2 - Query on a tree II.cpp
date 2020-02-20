/***************************************************
 * Problem Name : QTREE2 - Query on a tree II.cpp
 * Problem Link : https://www.spoj.com/problems/QTREE2/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2020-02-18
 * Problem Type : LCA
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
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
class LCA {
    public:
        vector<int>level, par;
        vector<vector<int> >road_cost, table;
        LCA (vector<vector<int> > &adj, vector<vector<int>> &cost, int n) {
            level.resize (n + 1);
            par.resize (n + 1);
            road_cost.resize (n + 1);
            table.resize (n + 1);

            for (int i = 0; i <= n; i++) {
                road_cost[i].resize (17, 0);
                table[i].resize (17, -1);
            }

            par[1] = -1;
            level[1] = 0;
            road_cost[1][0] = 0;
            dfs (adj, cost, 1, -1);
            lca_build (n);
        }
        void dfs (vector<vector<int> > &adj, vector<vector<int>> &cost, int u, int p) {
            for (int i = 0; i < (int) adj[u].size(); i++) {
                int v = adj[u][i];

                if (v == p) continue;

                level[v] = level[u] + 1;
                par[v] = u;
                road_cost[v][0] = cost[u][i];
                dfs (adj, cost, v, u);
            }
        }
        void lca_build (int n) {
            for (int i = 1; i <= n; i++) {
                table[i][0] = par[i];
            }

            for (int j = 1; (1 << j) < n; j++) {
                for (int i = 1; i <= n; i++) {
                    if (table[i][j - 1] != -1) {
                        int x = table[i][j - 1];
                        table[i][j] = table[x][j - 1];
                        road_cost[i][j] = road_cost[i][j - 1] + road_cost[x][j - 1];

                    }
                }
            }
        }
        int lca_query (int u, int v) {
            if (level[u] < level[v]) swap (u, v);

            int lim = log2 (level[u]);

            for (int i = lim; i >= 0; i--) {
                if (level[u] - (1 << i) >= level[v]) {
                    u = table[u][i];
                }
            }

            if (u == v) return u;

            for (int i = lim; i >= 0; i--) {
                if (table[u][i] != -1 && table[u][i] != table[v][i]) {
                    u = table[u][i];
                    v = table[v][i];
                }
            }

            return par[u];
        }
        int get_cost (int u, int v) {
            int len = level[u] - level[v];
            int sum = 0;
            int lim = log2 (len);

            for (int i = lim; i >= 0; i--) {
                if ( (1 << i) <= len) {
                    sum = sum + road_cost[u][i];
                    u = table[u][i];
                    len -= (1 << i);
                }

                if (len == 0) break;
            }

            return sum;
        }
        int get_kth(int u, int v,int k){
			int x = lca_query(u,v);
			int len = level[u] - level[x]+1;
			if(k>len){
				len = k-len;
				len = (level[v] - level[x]) - len;
				
				int lim = log2(len);
				for(int i = lim; i>=0; i--){
					if((1<<i)<=len){
						v = table[v][i];
						len-=(1<<i);
					}
					if(len == 0)break;
				}
				return v;
			}else{
				len = k-1;
				int lim = log2(len);
				for(int i = lim; i>=0; i--){
					if((1<<i)<=len){
						u = table[u][i];
						len-=(1<<i);
					}
					if(len == 0)break;
				}
				return u;
			}
			
		}
};

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int> > adj (n + 1), cost (n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb (v);
            adj[v].pb (u);
            cost[u].pb (w);
            cost[v].pb (w);
        }

        LCA obj (adj, cost, n);
        string str;

        while (cin >> str) {
            if (str == "DONE") {
                break;
            }

            if (str == "DIST") {
                int u, v;
                cin >> u >> v;
                int x = obj.lca_query (u, v);
                int res = obj.get_cost (u, x) + obj.get_cost (v, x);
                cout << res << "\n";

            } else if (str == "KTH") {
                int u, v, k;
                cin >> u >> v >> k;
                int res = obj.get_kth(u, v, k);
                cout << res << "\n";
            }
        }
    }

    return 0;
}
/*
1

6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2
KTH 4 6 4
DIST 4 6

*/
