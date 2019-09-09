/***************************************************
 * Problem Name : 1064 - Throwing Dice.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1064
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
ll n, x;
ll dp[27][155][7];
ll fun (int pos, int sum, int pre) {
    if (pos > n) {
        if (sum >= x) {
            return 1LL;

        } else {
            return 0LL;
        }
    }

    ll &ans = dp[pos][sum][pre];

    if (ans != -1) return ans;

    ans = 0;

    for (int i = 1; i <= 6; i++) {
        ans += fun (pos + 1, sum + i, i);
    }

    return ans;
}
ll Pow (ll num) {
    ll sum = 1;

    for (int i = 1; i <= num; i++) {
        sum *= 6LL;
    }

    return sum;
}

int main () {
    //~ __FastIO;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> x;
        SET (dp, -1);
        ll ans = fun (1, 0, 0);
        ll total = Pow (n);
        ll gc = __gcd (ans, total);
        ll a  = ans / gc;
        ll b = total / gc;

        if ( (a == 1 && b == 1) || ans == 0) {
            cout << "Case " << t << ": " << a << "\n";

        } else if (ans == 0) {
            cout << "Case " << t << ": " << ans << "\n";

        } else {
            cout << "Case " << t << ": " << a << "/" << b << "\n";
        }
    }

    return 0;
}
