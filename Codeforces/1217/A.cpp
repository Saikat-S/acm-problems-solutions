/***************************************************
 * Problem Name : A.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-09-05
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

int bi (int n, int val) {
    int low = 0, high = n;
    int ans;

    while (high >= low) {
        int mid = (high + low) / 2;
        int x1 = n - mid;
        int x2 = val + mid;

        //~ cout << mid << " --\n";
        if (x1 > x2) {
            low = mid + 1;
            ans = mid;

        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        int st, in, ex;
        cin >> st >> in >> ex;

        if (st > in) {
            int xx = (st + ex);
            int x1 = bi (xx, in) + 1;
            //~ cout << x1 << " --\n";
            cout << max (x1, 1) << "\n";

        } else {
            int x = (in - st);

            if (x > ex) {
                cout << 0 << "\n";

            } else {
                ex -= x;
                if (ex <= 0) {
                    cout << 0 << "\n";
                    continue;
                }
                x++;
                ex--;
                st = st + x;


                int xx = (st + ex);
                int x1 = bi (xx, in) + 1;
                //~ cout << x1 << " --\n";
                cout << max (x1, 0) << "\n";
            }
        }
    }

    return 0;
}
