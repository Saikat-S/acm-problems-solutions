/***************************************************
 * Problem Name : 1024 - Eid.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1024
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2020-11-29
 * Problem Type : Number Theory
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
#define MAX 10005
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
char mark[MAX];
vector<int>prime;
map<int, int>mp;
void sieve (int n) {
    int sq = sqrt (n) + 1;
    mark[0] = mark[1] = 1;

    for (int i = 4; i < n; i += 2) {
        mark[i] = 1;
    }

    for (int i = 3; i <= sq; i += 2) {
        for (int j = i * i; j < n; j += (2 * i) ) {
            mark[j] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if (!mark[i]) prime.pb (i);
    }
}

void prime_fact (int n) {
    int sq = (int) sqrt (n);

    for (int i = 0; i < (int) prime.size() && prime[i] <= sq ; i++) {
        int cnt = 0;

        while (n % prime[i] == 0) {
            cnt++;
            n /= prime[i];
        }

        mp[prime[i]] = max (cnt, mp[prime[i]]);
        sq = sqrt (n);
    }

    if (n > 1) {
        mp[n] = max (1, mp[n]);
    }
}


string multiply ( string a, int b ) {
    // a contains the biginteger in reversed form
    reverse (all (a) );
    int carry = 0;

    for ( int i = 0; i < (int) a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }

    while ( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }

    reverse (all (a) );
    return a;
}

int main () {
    //~ __FastIO;
    //~ cout << setprecision (10) << fixed;
    sieve (MAX);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            prime_fact (x);
        }

        string ans = "1";

        for (auto it : mp) {
            for (int i = 0; i < it.S; i++) {
                ans = multiply (ans, it.F);
            }
        }

        cout << "Case " << t << ": ";
        cout << ans << "\n";
        mp.clear();
    }

    return 0;
}
