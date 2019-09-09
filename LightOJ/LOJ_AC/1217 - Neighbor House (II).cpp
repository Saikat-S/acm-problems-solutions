/***************************************************
 * Problem Name : 1217 - Neighbor House (II).cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1217
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-08-31
 * Problem Type : DP
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
#define MAX 1005
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
int n, ar[MAX];
int dp[MAX][2];
int fun (int pos, int one_take) {
    if (pos > n) {
        return 0;
    }

    int &ans = dp[pos][one_take];

    if (ans != - 1) return ans;

    int res1 = 0, res2 = 0;
    ans = 0;

    if (pos == n) {
        if (one_take == 0) {
            res1 = ar[pos] + fun (pos + 2, one_take);
        }

    } else {
        res1 = ar[pos] + fun (pos + 2, one_take);
    }

    res2 = fun (pos + 1, one_take);
    return ans = max (res1, res2);
}

int main () {
    //~ __FastIO;
    int tc;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf ("%d", &ar[i]);
        }

        SET (dp, -1);
        int ans1 = fun (2, 0);
        int ans2 = ar[1] + fun (3, 1);
        int ans = max (ans1, ans2);
        printf ("Case %d: %d\n", t, ans);
    }

    return 0;
}
