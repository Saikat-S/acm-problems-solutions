/***************************************************
 * Problem Name : D.cpp
 * Problem Link :
 * OJ           :
 * Verdict      : Trying
 * Date         : 2020-02-16
 * Problem Type :
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

//~ const int MAX_N = 100000005;

//~ int vis [MAX_N];

ll fun (ll n) {
    if (n <= 0) return 0LL;
    else return (n * (n + 1LL) ) / 2LL;
}
int main () {
    //~ __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    ll n, k;
    cin >> n >> k;
    vector<ll>vec (n);
    ll posi = 0, negi = 0;
    ll zero = 0;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];

        if (vec[i] > 0) {
            posi++;

        } else if (vec[i] < 0) {
            negi++;

        } else {
            zero++;
        }
    }

    sort (all (vec) );
    ll total = (n * (n - 1LL) ) / 2LL;
    ll neg_num = negi * posi;
    ll pos_num = fun (posi - 1) + fun (negi - 1);
    ll zero_num =  total - neg_num - pos_num;
    cout << total << " : " << neg_num << " " << zero_num << " " << pos_num << "\n";

    if (k <= neg_num) {
        // kth number is a negative number
        ll kth = k;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            if (kth > posi) {
                kth -= posi;

            } else {
                //~ cout << vec[i] << " " << kth << " --\n";
                ll cnt = 0;

                for (int j = i + 1; j < n; j++) {
                    if (vec[j] > 0) cnt++;

                    if (cnt == kth) {
                        ans = vec[i] * vec[j];
                        break;
                    }
                }
            }

            if (ans != 0) break;
        }

        cout << ans << "\n";

    } else if (k <= neg_num + zero_num) {
        // kth number is a zero number
        cout << 0 << "\n";

    } else {
        // kth number is a positiv number
        int kth = k - neg_num - zero_num;
        ll ans = kth;
        vector<ll>v1, v2;

        for (int i = 0; i < n; i++) {
            if (vec[i] > 0) v1.pb (vec[i]);
            else if (vec[i] < 0) v2.pb (vec[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}
