/***************************************************
 * Problem Name : 1123 - Trail Maintenance.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1123
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-08
 * Problem Type : Graph(MST)
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
#define MAX 205
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
struct Edge {
    int u, v, w;
    bool operator < (const Edge &p) const {
        return w < p.w;
    }
};
vector<Edge>Ed;
int par[MAX];
int sz[MAX];
int n, sum;
bool flag;

int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}

void make (int u, int v) {
    if (u == v) return;

    if (sz[u] < sz[v]) swap (u, v);

    par[v] = u;
    sz[u] += sz[v];

    if (sz[u] >= n) flag = true;
}

int mst (int n) {
    sort (all (Ed) );
    vector<Edge>E;

    for (int i = 0; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    int sum = 0, cnt = 0;

    for (int i = 0; i < (int) Ed.size(); i++) {
        int u = find (par[Ed[i].u]);
        int v = find (par[Ed[i].v]);

        if (u != v) {
            make (u, v);
            sum += Ed[i].w;
            cnt++;
            Edge get;
            get.u = Ed[i].u;
            get.v = Ed[i].v;
            get.w = Ed[i].w;
            E.pb (get);

            if (cnt == n - 1) {
                break;
            }
        }
    }

    Ed.clear();
    Ed = E;
    return sum;
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, w;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &w);

        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }

        printf ("Case %d:\n", t);
        flag = false;

        for (int i = 0; i < w; i++) {
            int u, v, w;
            scanf ("%d %d %d", &u, &v, &w);
            Edge get;
            get.u = u, get.v = v, get.w = w;
            Ed.pb (get);
            make (find (par[u]), find (par[v]) );

            if (!flag) {
                printf ("-1\n");

            } else {
                int sum = mst (n);
                printf ("%d\n", sum);
            }
        }

        Ed.clear();
    }

    return 0;
}
