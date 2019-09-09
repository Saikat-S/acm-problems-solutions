/***************************************************
 * Problem Name : 1174 - Commandos.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1174
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-08-29
 * Problem Type : Graph
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
#define pii pair<ll,ll>
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
#define srt(v) sort(v.begin(), v.end())
#define r_srt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 105
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
vector<int>V[MAX];
int cost1[MAX], cost2[MAX];
bool vis[MAX];
void bfs (int s) {
    SET (vis, false);
    queue<int>Q;
    Q.push (s);
    cost1[s] = 0;
    vis[s] = true;

    while (!Q.empty() ) {
        int u = Q.front();
        Q.pop();
        int sz = V[u].size();

        for (int i = 0; i < sz; i++) {
            int v = V[u][i];

            while (!vis[v]) {
                cost1[v]  = cost1[u] + 1;
                vis[v] = true ;
                Q.push (v);
            }
        }
    }
}
void bfs1 (int s) {
    SET (vis, false);
    queue<int>Q;
    Q.push (s);
    cost2[s] = 0;
    vis[s] = true;

    while (!Q.empty() ) {
        int u = Q.front();
        Q.pop();
        int sz = V[u].size();

        for (int i = 0; i < sz; i++) {
            int v = V[u][i];

            while (!vis[v]) {
                cost2[v]  = cost2[u] + 1;
                vis[v] = true ;
                Q.push (v);
            }
        }
    }
}
int main() {
    int n, e, tc, sum;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        sum = 0;
        scanf ("%d %d", &n, &e);

        for (int i = 1; i <= e; i++) {
            int x, y;
            scanf ("%d %d", &x, &y);
            V[x].push_back (y);
            V[y].push_back (x);
        }

        int s, d;
        scanf ("%d %d", &s, &d);
        bfs (s);
        bfs1 (d);
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum = max (sum, cost1[i] + cost2[i]);
        }

        printf ("Case %d: %d\n", t, sum);

        for (int i = 0; i < MAX; i++) {
            V[i].clear();
        }
    }

    return 0;
}
