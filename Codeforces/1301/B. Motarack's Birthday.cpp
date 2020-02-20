/***************************************************
 * Problem Name : B. Motarack's Birthday.cpp
 * Problem Link : https://codeforces.com/contest/1301/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-02-13
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
ll n, ar[MAX];

bool isC (ll x, ll mid) {
    if (x < 0) return false;

    for (int i = 1; i < n; i++) {
        ll x1 = ar[i - 1];
        ll x2 = ar[i];

        if (x1 == -1) x1 = x;

        if (x2 == -1) x2 = x;

        ll X = abs (x1 - x2);

        if (X > mid) {
            return false;
        }
    }

    return true;
}

bool isV (ll mid) {
    ll mn = INF;
    ll mx = 0;

    for (int i = 1; i < n; i++) {
        ll x1 = ar[i - 1];
        ll x2 = ar[i];

        if (x1 != -1) {
            mx = max (mx, x1);
            mn = min (mn, x1);
        }

        if (x2 != -1) {
            mx = max (mx, x2);
            mn = min (mn, x2);
        }
    }

    ll x = mx + mid;
    ll x1 = mx - mid;
    ll xx = mn - mid;;
    ll xx1 = mn + mid;;

    if (isC (x, mid) || isC (x1, mid) || isC (xx, mid) || isC (xx1, mid) ) {
        return true;

    } else {
        return false;
    }
}

ll bi() {
    ll low = 0, high = 1000000000LL;
    ll ans = -1;

    while (high >= low) {
        ll mid = (high + low) / 2LL;

        if (isV (mid) == true) {
            //~ cout << mid << " --mid\n";
            ans = mid;
            high = mid - 1LL;

        } else {
            low = mid + 1LL;
        }
    }

    return ans;
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        ll mn = INF;
        ll mx = 0;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];

            if (ar[i] != -1) mn = min (mn, ar[i]);

            mx  = max (mx, ar[i]);
        }

        if (mn == INF) {
            cout << 0 << " " << 0 << "\n";
            continue;
        }

        ll ans = bi();
        ll x1 = mn + ans;
        ll x2 = mx - ans;
        ll x3 = mn - ans;
        ll x4 = mx + ans;

        if (isC (x1, ans) ) {
            cout << ans << " " << x1 << "\n";

        } else if (isC (x2, ans) ) {
            cout << ans << " " << x2 << "\n";

        } else if (isC (x3, ans) ) {
            cout << ans << " " << x3 << "\n";

        } else if (isC (x4, ans) ) {
            cout << ans << " " << x4 << "\n";
        }
    }

    return 0;
}
