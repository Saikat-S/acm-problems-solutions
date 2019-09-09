/***************************************************
 * Problem Name : 1283 - Shelving Books.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1283
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-08-31
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
int n, ar[MAX], mp[100005];
int dp[MAX][MAX][MAX];
int fun (int pos, int left, int right) {
    if (pos == n) {
        return 0;
    }

    int &ans = dp[pos][left][right];

    if (ans != -1) return ans;

    int a = 0, b = 0, c = 0;
    ans = 0;

    if (left <= mp[ar[pos]] && mp[ar[pos]] <= right) {
        a = 1 + fun (pos + 1, mp[ar[pos]], right);
    }

    if (right >= mp[ar[pos]] && mp[ar[pos]] >= left) {
        b = 1 + fun (pos + 1, left, mp[ar[pos]]);
    }

    c = fun (pos + 1, left, right);
    return ans = Max3 (a, b, c);
}



int main () {
    //~ __FastIO;
    int tc;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d", &n);
        set<int>st;

        for (int i = 0; i < n; i++) {
            scanf ("%d", &ar[i]);
            st.insert (ar[i]);
        }

        SET (mp, 0);
        int k = 1;

        for (auto it = st.begin(); it != st.end(); it++) {
            if (mp[*it] == 0) {
                mp[*it] = k++;
            }
        }

        SET (dp, -1);
        int ans = fun (0, 0, 103);
        printf ("Case %d: %d\n", t, ans);
    }

    return 0;
}

