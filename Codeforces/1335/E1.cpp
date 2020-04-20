/***************************************************
 * Problem Name : E1.cpp
 * Problem Link : https://codeforces.com/contest/1335/problem/E1
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2020-04-13
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
#define MAX 200005
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
int sum[MAX][27];
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int>vec (n + 1);

        for (int i = 1; i <= 200; i++) {
            sum[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            cin >> vec[i];

            for (int j = 1; j <= 200; j++) {
                if (vec[i] == j) {
                    sum[i][j] = sum[i - 1][j] + 1;

                } else {
                    sum[i][j] = sum[i - 1][j];
                }
            }
        }

        vector<int>suf[27];
        int sum_suf[27];

        for (int i = 0; i <= 26; i++) {
            suf[i].pb (0);
            sum_suf[i] = 0;
        }

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= 26; j++) {
                if (vec[i] == j) {
                    sum_suf[j] = sum_suf[j] + 1;
                }

                suf[j].pb (sum_suf[j]);
            }
        }

        int cnt = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= 26; j++) {
                int a = sum[i][j];
                int lw = lower_bound (all (suf[j]), a) - suf[j].begin();
                int up = upper_bound (all (suf[j]), a) - suf[j].begin();
                int nn = n - lw;

                if (lw != up) {
                    if (nn > i) {
                        int tmp = 0;

                        for (int k = 1; k <= 26; k++) {
                            tmp = max (tmp, sum[n - lw][k] - sum[i][k]);
                        }

                        int ans = a + a + tmp;
                        cnt = max (cnt, ans);
                    }
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
