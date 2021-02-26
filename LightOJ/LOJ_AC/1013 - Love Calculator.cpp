/***************************************************
 * Problem Name : 1013 - Love Calculator.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1013
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2020-12-12
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
string A, B;
int dp1[33][33];
ll dp2[33][33][33];
int n, m;
int lcs (int i, int j) {
    if (i >= n || j >= m) {
        return 0;
    }

    int &res = dp1[i][j];

    if (res != -1) return res;

    res = 0;

    if (A[i] == B[j]) {
        res = 1 + lcs (i + 1, j + 1);

    } else {
        int res1 = lcs (i + 1, j);
        int res2 = lcs (i, j + 1);
        res = max (res1, res2);
    }

    return res;
}

ll fun (int i, int j, int cnt, int &len) {
    if (i >= n) {
        cnt += (m - j);

        if (cnt == len) return 1LL;
        else return 0LL;
    }

    if (j >= m) {
        cnt += (n - i);

        if (cnt == len) return 1LL;
        else return 0LL;
    }

    ll &res = dp2[i][j][cnt];

    if (res != -1) return res;

    if (A[i] == B[j]) {
        res = fun (i + 1, j + 1, cnt + 1, len);

    } else {
        res = fun (i + 1, j, cnt + 1, len) + fun (i, j + 1, cnt + 1, len);
    }

    return res;
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> A >> B;
        n = (int) A.size(), m = (int) B.size();
        SET (dp1, -1);
        SET (dp2, -1);
        int res1 = (n + m) - lcs (0, 0);
        ll res2 = fun (0, 0, 0, res1);
        cout << "Case " << t << ": ";
        cout << res1 << " " << res2 << "\n";
    }

    return 0;
}
