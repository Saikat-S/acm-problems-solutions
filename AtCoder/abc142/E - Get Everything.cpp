/***************************************************
 * Problem Name : E - Get Everything.cpp
 * Problem Link : https://atcoder.jp/contests/abc142/tasks/abc142_e
 * OJ           : atCoder
 * Verdict      : AC
 * Date         : 2020-01-04
 * Problem Type : ABC- E (DP)
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
#define MAX 5005
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
int n, m;
int ar[1005];
int cr[1005];

int dp[1005][1 << 13];

int fun (int pos, int mask) {
    if (pos == m) {
        if (mask == (1 << n) - 1) {
            return 0;

        } else {
            return INF;
        }
    }

    int &res = dp[pos][mask];

    if (res != -1) return res;

    int res1 = cr[pos] + fun (pos + 1, mask | ar[pos]);
    int res2 = fun (pos + 1, mask);
    res = min (res1, res2);
    return res;
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    cin >> n >> m;
    set<int>st;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int mask = 0;

        for (int j = 0; j < b; j++) {
            int x;
            cin >> x;
            st.insert (x);
            x--;
            mask += (1 << x);
        }

        ar[i] = mask;
        cr[i] = a;
    }

    if ( (int) st.size() != n) {
        cout << -1 << "\n";

    } else {
        SET (dp, -1);
        int ans = fun (0, 0);
        cout << ans << "\n";
    }

    return 0;
}
