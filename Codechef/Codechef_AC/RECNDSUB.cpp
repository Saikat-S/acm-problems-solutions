/***************************************************
 * Problem Name : RECNDSUB.cpp
 * Problem Link : https://www.codechef.com/RC122020/problems/RECNDSUB
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2020-04-29
 * Problem Type : Combinatorics
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
#define MOD 163577857

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
ll f[MAX], invf[MAX];
ll two[MAX];
ll bigMod (ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b & 1) res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

ll ncr (ll n, ll r) {
    if (r < 0 || r > n) {
        return 0;
    }

    return ( (f[n] * invf[r]) % MOD * invf[n - r]) % MOD;
}


void init() {
    two[0] = 1;
    f[0] = 1;
    invf[0] = bigMod (f[0], MOD - 2);

    for (int i = 1; i < MAX; i++) {
        f[i] = (f[i - 1] * i) % MOD;
        invf[i] = bigMod (f[i], MOD - 2);
        two[i] = (two[i - 1] * 2LL) % MOD;
    }
}
int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    init();
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int>vec (n);
        map<int, ll>mp;

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            mp[vec[i]]++;
        }

        for (int i = -n; i <= n; i++) {
            ll res = (two[mp[0]] * ncr (mp[1] + mp[-1], mp[-1] + i))%MOD;

            if (i == 0) {
                res--;

                if (res < 0) res += MOD;
            }

            cout << res << " ";
        }

        nl;
    }

    return 0;
}
