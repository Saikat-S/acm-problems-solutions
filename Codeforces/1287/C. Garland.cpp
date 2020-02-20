/***************************************************
 * Problem Name : C. Garland.cpp
 * Problem Link : https://codeforces.com/contest/1287/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-01-06
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
#define MAX 105
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
int ar[MAX];
int n;

int dp[MAX][MAX][MAX][5];

bool isV (int a, int b) {
    if ( (a & 1) && (b & 1) ) return false;
    else if (! (a & 1) && ! (b & 1) ) return false;
    else return true;
}

int fun (int pos, int od, int ev, int pre) {
    if (pos >= n) {
        return 0;
    }

    int &res = dp[pos][od][ev][pre];

    if (res != -1) return res;

    int res1 = INF, res2 = INF;

    if (pos == 0) {
        if (ar[pos] == 0) {
            if (od != 0) {
                res1 = fun (pos + 1, od - 1, ev, 1);
            }

            if (ev != 0) {
                res2 = fun (pos + 1, od, ev - 1, 2);
            }

        } else {
            if (ar[pos] & 1) pre = 1;
            else pre = 2;

            res1 = fun (pos + 1, od, ev, pre);
            res2 = fun (pos + 1, od, ev, pre);
        }

    } else {
        if (ar[pos] == 0) {
            if (od != 0) {
                int v = 0;

                if (isV (pre, 1) ) v = 1;

                res1 = v + fun (pos + 1, od - 1, ev, 1);
            }

            if (ev != 0) {
                int v = 0;

                if (isV (pre, 2) ) v = 1;

                res2 = v + fun (pos + 1, od, ev - 1, 2);
            }

        } else {
            int v = 0;

            if (isV (pre, ar[pos]) ) v = 1;

            if (ar[pos] & 1) pre = 1;
            else pre = 2;

            res1 = v + fun (pos + 1, od, ev, pre);
            res2 = v + fun (pos + 1, od, ev, pre);
        }
    }

    return res = min (res1, res2);
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    cin >> n;
    map<int, bool>mp;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mp[ar[i]] = true;
    }

    int od = 0, ev = 0;

    for (int i = 1; i <= n; i++) {
        if (!mp[i]) {
            if (i & 1) od++;
            else ev++;
        }
    }

    SET (dp, -1);
    int ans = fun (0, od, ev, 0);
    cout << ans << "\n";
    return 0;
}
