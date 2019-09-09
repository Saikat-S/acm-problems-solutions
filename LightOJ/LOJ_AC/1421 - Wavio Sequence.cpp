/***************************************************
 * Problem Name : 1421 - Wavio Sequence.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1421
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-08-31
 * Problem Type : DP(LIS)
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
int L[MAX], I[MAX];
int L1[MAX], I1[MAX];
vector<int>ar, ar1;
void LIS (int n) {
    I[0] = -INF;

    for (int i = 1; i <= n; i++) {
        I[i] = INF;
    }

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int low = 0, high = maxLen, mid;

        while (high >= low) {
            mid = (low + high) / 2;

            if (I[mid] < ar[i]) {
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }

        I[low] = ar[i];
        L[i] = low;

        if (maxLen < low) {
            maxLen = low;
        }
    }
}

void LDS (int n) {
    I1[0] = -INF;

    for (int i = 1; i <= n; i++) {
        I1[i] = INF;
    }

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int low = 0, high = maxLen, mid;

        while (high >= low) {
            mid = (low + high) / 2;

            if (I1[mid] < ar1[i]) {
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }

        I1[low] = ar1[i];
        L1[i] = low;

        if (maxLen < low) {
            maxLen = low;
        }
    }
}
int main () {
    //~ __FastIO;
    int tc, n;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ar.pb (x);
            ar1.pb (x);
        }

        LIS (n);
        reverse (all (ar1) );
        LDS (n);
        int LL[MAX];

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            LL[j] = L1[i];
        }

        int mx = 0;

        for (int i = 0; i < n; i++) {
            int mn = min (L[i], LL[i]);
            mx = max (mx, mn);
        }

        cout << "Case " << t << ": " << (mx * 2) - 1 << "\n";
        ar.clear();
        ar1.clear();
    }

    return 0;
}
