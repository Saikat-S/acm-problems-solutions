/***************************************************
 * Problem Name : C.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2020-04-26
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

ll fun (ll a, ll b, ll l, ll r) {
    ll ans  = 0;

    for (ll i = l; i <= r; i++) {
        ll v1 = (i % a) % b;
        ll v2 = (i % b) % a;

        if (v1 != v2) {
            ans++;
            //~ ans = i;
            //~ break;

        } else {
            cout << i << " : " << v1 << " " << v2 << "\n";
        }
    }

    return ans;
}

ll solve (ll a, ll b, ll l, ll r) {
    ll ans = 0;
    ll v1, v2;
    ll gc = __gcd (a, b);
    ll inc = (a * b) / gc;

    for (ll i = 1; ; i += 2) {
        if (i == 1) {
            v1 = 1;
            v2 = max (a, b) - 1;
            i = 0;

        } else {
            if (v1 == 1) {
                v1 += (inc - 1);

            } else {
                v1 += inc;
            }

            v2 = v1 + max (a, b) - 1;
        }

        //~ cout << v1 << " " << v2 << " :v1v2\n";
        if (v1 > r) break;

        if (v1 >= l && v2 <= r) {
            ans += (v2 - v1) + 1LL;

        } else {
            if (l >= v1 && r <= v2) {
                ans += (r - l) + 1;
                //~ break;

            } else if (v2 >= l && v2 <= r) {
                ans += (v2 - max (v1, l) ) + 1LL;

            } else if (v1 >= l && v1 <= r) {
                ans += (min (r, v2) - v1) + 1LL;
            }
        }
    }

    return ans;
}

ull bi (ull a, ull b, ull val) {
    ull low = 1, high = 9000000000000;
    ull gc = __gcd (a, b);
    ull ans = 0;

    while (high >= low) {
        ull mid = (high + low) / 2;
		ull v1 = ( (a * b) / gc) * mid;
        ull v2 = v1 + (max (a, b) - 1LL);

        if (v2 <= val) {
            ans = mid;
            low = mid + 1;

        } else {
            high = mid - 1;
        }
    }
    ull res = max(a, b)-1;
    if (ans == 0) {
		res = min(max(a, b)-1LL, val);
		ull v1 = ( (a * b) / gc);
		ull v2 = v1 + (max (a, b) - 1LL);
		
		if(val>=v1 && val<=v2){
			res+= ((val-v1)+1LL);
		}
		
    } else {
        res += (ans * (max(a, b)));
        
       ull v1 = ( (a * b) / gc) * ans;
       v1+=( (a * b) / gc);
       if(v1<=val){
		   res+=((val-v1)+1LL);
	   }
        
    }
    return res;
}


int main () {
    //~ __FastIO;
    //~ cout << setprecision (10) << fixed;
    int tc;
    cin >> tc;

    while (tc--) {
        ull a, b, q;
        cin >> a >> b >> q;
        
        while (q--) {
            ull l, r;
            cin >> l >> r;
            ull al = (r - l)+1LL;
            //~ if (b % a == 0  || a % b == 0) {
                //~ cout << 0 << " ";
                //~ continue;
            //~ }

            //~ ll ans = fun (a, b, l, r);
            //~ ll ans1 = solve (a, b, l, r);
            //~ ll ans2 = al - ans1;
            ull br = bi(a, b, r);
            ull bl = bi(a, b, l-1);
            //~ cout << br << " " << bl << "\n";
            //~ cout << br << " " << bl << "\n";
            ull ans3 = al - (br - bl);
            //~ cout << ans << "  :fun\n";
            //~ cout << ans3 << "  :ans3\n";
            //~ cout << ans1 << " :ans1\n";
            //~ cout << ans2 << " :ans2\n";
            cout << ans3 << " ";
            //~ cout << ans2 << " ";
        }

        nl;
    }

    return 0;
}
