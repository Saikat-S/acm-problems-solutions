/***************************************************
 * Problem Name : C.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2021-03-10
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

long double get (long double a, long double b) {
    long double tmp = sqrt ((a * a) + (b * b));
    return tmp;
}

int main () {
    __FastIO;
    cout << setprecision (16) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int>di, mi;

        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;

            if (x == 0) {
                mi.pb (abs (y));
            }

            if (y == 0) {
                di.pb (abs (x));
            }
        }

        sort (all (mi));
        sort (all (di));
        long double sum1 = 0;
        int i = 0, j = (int)mi.size() - 1;

        for (int k = 0; k < (int)di.size(); k++) {
            long double tmp1 = get (abs (di[k]), abs (mi[i]));
            long double tmp2 = get (abs (di[k]), abs (mi[j]));

            if (tmp1 > tmp2) {
                sum1 += tmp2;
                j--;

            } else {
                sum1 += tmp1;
                i++;
            }
        }

        long double sum2 = 0;
        i = 0, j = (int)di.size() - 1;

        for (int k = 0; k < (int)di.size(); k++) {
            long double tmp1 = get (abs (mi[k]), abs (di[i]));
            long double tmp2 = get (abs (mi[k]), abs (di[j]));

            if (tmp1 > tmp2) {
                sum2 += tmp2;
                j--;

            } else {
                sum2 += tmp1;
                i++;
            }
        }

        long double sum = min (sum1, sum2);
        cout << sum << "\n";
    }

    return 0;
}
