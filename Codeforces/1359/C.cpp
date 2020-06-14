/***************************************************
 * Problem Name : C.cpp
 * Problem Link : https://codeforces.com/contest/1359/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-05-28
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
#define rev(v) reverse(v.rbegin(), v.rend())
#define Sqr(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define F first
#define S second
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
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/
ll bi (ll h, ll c, double t) {
    ll low = 1, high = INF;
    ll ans = INF;

    for (int i = 1; i <= 300; i++) {
        ll mid = (high + low) / 2;
        double val = (mid * h) + ( (mid - 1) * c);
        double cnt = (mid * 2) - 1;
        double avg = val / cnt;

        if (avg >= t) {
            low = mid + 1;
            ans = mid;

        } else {
            high = mid - 1;
        }
    }

    return ans;
}
ll bi1 (ll h, ll c, double t) {
    ll low = 1, high = INF;
    ll ans = INF;

    for (int i = 1; i <= 300; i++) {
        ll mid = (high + low) / 2;
        double val = (mid * h) + ( (mid - 1) * c);
        double cnt = (mid * 2) - 1;
        double avg = val / cnt;

        if (avg <= t) {
            high = mid - 1;
            ans = mid;

        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main () {
    __FastIO;
    //~ cout << setprecision (5) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        ll h, c, t;
        cin >> h >> c >> t;
        ll cnt1 = bi (h, c, t);
        ll cnt2 = bi1 (h, c, t);
        double val = (cnt1 * h) + ( (cnt1 - 1) * c);
        double cnt = (cnt1 * 2) - 1;
        double avg1 = val / cnt;
        val = (cnt2 * h) + ( (cnt2 - 1) * c);
        cnt = (cnt2 * 2) - 1;
        double avg2 = val / cnt;
        double avg3 = double (c + h) / 2.00;
        double t1 =  abs (t - avg1);
        double t2 =  abs (t - avg2);
        double t3 =  abs (t - avg3);
        cnt1 = (cnt1 * 2) - 1;
        cnt2 = (cnt2 * 2) - 1;

        if (t1 == t2) {
            if (t1 == t3) {
                cout << min (2LL, min (cnt1, cnt2) ) << "\n";

            } else if (t1 > t3) {
                cout << 2 << "\n";

            } else {
                cout << min (cnt1, cnt2) << "\n";
            }

        } else if (t1 > t2) {
            if (t2 == t3) {
                cout << min (2LL, cnt2) << "\n";

            } else if (t2 > t3) {
                cout << 2 << "\n";

            } else {
                cout << cnt2 << "\n";
            }

        } else {
            if (t1 == t3) {
                cout << min (2LL, cnt1) << "\n";

            } else if (t1 > t3) {
                cout << 2 << "\n";

            } else {
                cout << cnt1 << "\n";
            }
        }
    }

    return 0;
}
