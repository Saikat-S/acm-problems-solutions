/***************************************************
 * Problem Name : D.cpp
 * Problem Link : https://codeforces.com/contest/1380/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-07-12
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
#include <chrono>
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
#define un_map unordered_map
#define un_set unordered_set
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
struct custom_hash {
    static uint64_t splitmix64 (uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30) ) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27) ) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator() (uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                        chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64 (x + FIXED_RANDOM);
    }
};
ll lcm ( ll a, ll b ) {
    return ( a / __gcd ( a, b ) ) * b;
}
/************************************ Code Start Here ******************************************************/

ll get_min (ll len, ll x, ll k, ll y) {
    ll need = (len % k);
    ll res = ( need * y);
    len -= need;
    ll cnt = len / k;
    ll x1 = cnt * x;
    ll x2 = len * y;
    res += min (x1, x2);
    return res;
}

int main () {
    //~ __FastIO;
    //~ cout << seetprecision (10) << fixed;
    //~ cout << get_min(0, 10, 3, 3) << "\n";
    ll n, m;
    ll x, k, y;
    cin >> n >> m;
    cin >> x >> k >> y;
    vector<ll>ar (n), br (m);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> br[i];
    }

    ll pre = 0;
    bool f = 0;
    int i = 0, j = 0;
    ll sum = 0;

    while (j < m) {
        if (ar[i] == br[j]) {
            if (j == 0) {
                ll pos1 = -1;
                ll len = i;
                ll mx = ar[i];

                for (int ii = 0; ii < i; ii++) {
                    if (ar[ii] > mx) {
                        pos1 = ii;
                        break;
                    }
                }

                if (pos1 == -1) {
                    sum += get_min (len, x, k, y);

                } else {
                    if (len < k) {
                        f = 1;
                        break;

                    } else {
                        int need = len % k;
                        sum += need * y;
                        len -= need;

                        if (y * k >= x) {
                            sum += len / k * x;

                        } else {
                            sum += (len - k) * y + x;
                        }
                    }
                }

            } else {
                ll len = (i - pre) - 1;
                ll mx = max (ar[pre], ar[i]);
                ll pos1 = -1;

                for (int ii = pre + 1; ii < i; ii++) {
                    if (ar[ii] > mx) {
                        pos1 = ii;
                        break;
                    }
                }

                if (pos1 == -1) {
                    sum += get_min (len, x, k, y);

                } else {
                    if (len < k) {
                        f = 1;
                        break;

                    } else {
                        int need = len % k;
                        sum += need * y;
                        len -= need;

                        if (y * k >= x) {
                            sum += len / k * x;

                        } else {
                            sum += (len - k) * y + x;
                        }
                    }
                }

                //~ debug;
            }

            //~ cout << sum << "\n";
            pre = i;
            i++, j++;

        } else {
            i++;

            if (i >= n) {
                f = 1;
                break;
            }
        }
    }

    ll pos1 = -1;
    ll len = (n - pre) - 1;
    ll mx = ar[pre];

    for (int ii = pre + 1; ii < n; ii++) {
        if (ar[ii] > mx) {
            pos1 = ii;
            break;
        }
    }

    if (pos1 == -1) {
        sum += get_min (len, x, k, y);

    } else {
        if (len < k) {
            f = 1;

        } else {
            int need = len % k;
            sum += need * y;
            len -= need;

            if (y * k >= x) {
                sum += len / k * x;

            } else {
                sum += (len - k) * y + x;
            }
        }
    }

    if (f) {
        cout << -1 << "\n";

    } else {
        cout << sum << '\n';
    }

    return 0;
}
