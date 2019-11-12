/***************************************************
 * Problem Name : Messy Table.cpp
 * Problem Link : https://toph.co/p/messy-table
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-10-24
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
struct st {
    int l, w;
} ar[MAX];
int n;
int dp[MAX][MAX];
bool cmp (st a, st b) {
    if (a.l == b.l) {
        return a.w > b.w;

    } else {
        return a.l > b.l;
    }
}
bool cmp1 (st a, st b) {
    if (a.w == b.w) {
        return a.l > b.l;

    } else {
        return a.w > b.w;
    }
}

int fun (int pos, int pre) {
    if (pos >= n) return 0;

    int &ans = dp[pos][pre];

    if (ans != -1) return ans;

    int val1 = 0, val2 = 0;

    if ( (min (ar[pos].l, ar[pos].w) < ar[pre].w)
         && (max (ar[pos].l, ar[pos].w) < ar[pre].l) ) {
        val1 = 1 + fun (pos + 1, pos);
    }

    val2 = fun (pos + 1, pre);
    return ans = max (val1, val2);
}


int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i].l >> ar[i].w;

        if (ar[i].l < ar[i].w) swap (ar[i].l, ar[i].w);
    }

    sort (ar, ar + n, cmp);
    SET (dp, -1);
    int ans = fun (0, 0) + 1;
    sort (ar, ar + n, cmp1);
    SET (dp, -1);
    int ans1 = fun (0, 0) + 1;
    cout << max (ans1, ans) << "\n";
    return 0;
}
