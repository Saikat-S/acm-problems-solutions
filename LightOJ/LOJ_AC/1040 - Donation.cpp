/***************************************************
 * Problem Name : 1040 - Donation.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1040
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-09-07
 * Problem Type : Graph(mst)
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
#define MAX 55
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
    bool operator< (const Edge &p) const {
        return w < p.w;
    }
};
vector<Edge>E;
int par[MAX];

int find (int r) {
    if (r == par[r]) return r;
    else return par[r] = find (par[r]);
}

int mst (int n) {
    sort (all (E) );

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    int sum = 0, cnt = 0;

    for (int i = 0; i < (int) E.size(); i++) {
        int u = find (E[i].u);
        int v = find (E[i].v);

        if (u != v) {
            par[u] = v;
            cnt++;
            sum += E[i].w;

            if (cnt == n - 1 ) {
                break;
            }
        }
    }

    if (cnt != n - 1) {
        return -1;

    } else {
        return sum;
    }
}


int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc, n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        int total = 0;
        int donate = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x;
                cin >> x;

                if (i != j && x != 0) {
                    Edge get;
                    get.u = i;
                    get.v = j;
                    get.w = x;
                    E.pb (get);

                } else {
                    donate += x;
                }

                total += x;
            }
        }

        total -= donate;
        int ans = mst (n);
        cout << "Case " << t << ": ";

        if (ans == -1) cout << ans << "\n";
        else {
            donate += (total - mst (n) );
            cout << donate << "\n";
        }

        E.clear();
    }

    return 0;
}

