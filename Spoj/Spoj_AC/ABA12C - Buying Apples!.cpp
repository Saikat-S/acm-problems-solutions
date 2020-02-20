/***************************************************
 * Problem Name : ABA12C - Buying Apples!.cpp
 * Problem Link : https://www.spoj.com/problems/ABA12C/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2020-02-19
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
const int MAX_N = 105;

int n, k;
ll ar[MAX_N];
ll dp[MAX_N][MAX_N][MAX_N];

ll fun (int pos, int kinche, int koto) {
    if (pos > k) {
        if (koto == k) {
            return 0LL;

        } else {
            return INF;
        }
    }

    ll &res = dp[pos][kinche][koto];

    if (res != -1) return res;

    ll res1 = INF, res2 = INF;

    if (ar[pos] != -1) {
        if (kinche < n && koto + pos <= k) {
            res1 = ar[pos] + fun (pos, kinche + 1, koto + pos);
        }
    }

    res2 = fun (pos + 1, kinche, koto);
    return res = min (res1, res2);
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;

        for (int i = 1; i <= k; i++) {
            cin >> ar[i];
        }

        SET (dp, -1);
        ll res = fun (1, 0, 0);

        if (res == INF) {
            cout << -1 << "\n";

        } else {
            cout << res << "\n";
        }
    }

    return 0;
}
