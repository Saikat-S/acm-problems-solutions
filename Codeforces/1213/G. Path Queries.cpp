/***************************************************
 * Problem Name : G. Path Queries.cpp
 * Problem Link : https://codeforces.com/contest/1213/problem/G
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-08-31
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
#define pii pair<ll,ll>
#define pil pair <int, ll>
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/

struct edge {
    int u, v, w;
} Ed[MAX];
bool cmp (edge a, edge b) {
    return a.w < b.w;
}

int par[MAX];
int sz[MAX];
ll cnt;

ll fun (ll n) {
    return (n * (n + 1LL) ) / 2LL;
}

void init (int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find (int r) {
    if (par[r] == r) {
        return r;

    } else {
        return par[r] = find (par[r]);
    }
}

void make_set (int u, int v) {
    int uu = find (par[u]);
    int vv = find (par[v]);

    if (uu != vv) {
        if (sz[uu] < sz[vv]) swap (uu, vv);

        if (sz[uu] >= 2) {
            ll tmp = fun (sz[uu] - 1);
            cnt -= tmp;
        }

        if (sz[vv] >= 2) {
            ll tmp = fun (sz[vv] - 1);
            cnt -= tmp;
        }

        par[vv] = uu;
        sz[uu] += sz[vv];
        cnt += fun (sz[uu] - 1);
    }
}



int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int n, m;
    cin >> n >> m;
    init (n);
    int N = n - 1;

    for (int i = 0; i < N; i++) {
        cin >> Ed[i].u >> Ed[i].v >> Ed[i].w;
    }

    sort (Ed, Ed + N, cmp);
    vector<pii>vec;

    for (int i = 1; i <= m; i++) {
        int q;
        cin >> q;
        vec.pb ({q, i});
    }

    sort (all (vec) );
    int j = 0;
    vector<pil>ans;
    cnt = 0;

    for (int i = 0; i < (int) vec.size(); i++) {
        int xx = vec[i].first;
        int id  = vec[i].second;

        for (; j < N; j++) {
            int w = Ed[j].w;

            if (w > xx) break;

            int x = Ed[j].u;
            int y = Ed[j].v;
            make_set (x, y);
        }

        ans.pb ({id, cnt});
    }

    sort (all (ans) );

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].second << " ";
    }

    nl;
    return 0;
}
