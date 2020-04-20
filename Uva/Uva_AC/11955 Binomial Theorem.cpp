/***************************************************
 * Problem Name : 11955 Binomial Theorem.cpp
 * Problem Link :
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2020-04-18
 * Problem Type : Implementation
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
ll c_pascal (ll n, ll r) {
    ll v = 1;

    for (int i = 1; i <= r; i++) {
        v = v * (n + 1 - i) / i;
    }

    return v;
}
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        string str;
        cin >> str;
        string a, b;
        int k = 0;
        int pos = 1;

        for (; str[pos] != '+'; pos++) {
            a += str[pos];
        }

        for (pos = pos + 1; str[pos] != ')'; pos++) {
            b += str[pos];
        }

        string s_num = "";

        for (pos = pos + 2; pos < (int) str.size(); pos++) {
            s_num += str[pos];
        }

        k = toInt (s_num);
        string ans = "";

        for (int i = k, j = 0; i >= 0; i--, j++) {
            ll co = c_pascal (k, j);

            if (co != 1) {
                ans += toString (co);
                ans += "*";
            }

            bool f = false;

            if (i > 0) {
                ans += a;
                f = true;

                if (i > 1) {
                    ans += "^";
                    ans += toString (i);
                }
            }

            if (j > 0) {
                if (f) ans += "*";

                ans += b;

                if (j > 1) {
                    ans += "^";
                    ans += toString (j);
                }
            }

            if (i != 0) ans += "+";
        }

        cout << "Case " << t << ": " << ans << "\n";
    }

    return 0;
}
