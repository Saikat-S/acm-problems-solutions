/***************************************************
 * Problem Name : ACODE - Alphacode.cpp
 * Problem Link : https://www.spoj.com/problems/ACODE/
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
const int MAX_N = 5005;

string str;
ll dp[MAX_N][105];

ll fun (int pos, int x) {
    if (pos >= (int) str.size() ) {
        if (x <= 26 && x > 0) return 1LL;
        else return 0LL;
    }

    ll &res = dp[pos][x];

    if (res != -1) return res;

    ll res1 = 0, res2 = 0;

    if (str[pos] != '0') {
        if (pos + 1 < (int) str.size() ) {
            if (str[pos + 1] != '0') {
                res1 = fun (pos + 1, str[pos] - '0');
                int val = (str[pos] - '0') * 10 + (str[pos + 1] - '0');

                if (val <= 26) res2 = fun (pos + 2, val);

            } else {
                int val = (str[pos] - '0') * 10 + (str[pos + 1] - '0');

                if (val <= 26) res2 = fun (pos + 2, val);
            }

        } else {
            res1 = fun (pos + 1, str[pos] - '0');
        }
    }

    return res = res1 + res2;
}

int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    while (cin >> str) {
        if (str == "0") break;

        SET (dp, -1);
        ll res = fun (0, 0);
        cout << res << "\n";
    }

    return 0;
}
//1013
