/***************************************************
 * Problem Name : 1215 - Finding LCM.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1215
 * OJ           : LOJ
 * Verdict      : AC
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
#define MAX 1000005
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
vector<ll>prime, di;
vector<pii>fact;
char mark[MAX];

void sieve (int n) {
    mark[0] = mark[1] = 1;

    for (int i = 4; i < n; i += 2) {
        mark[i] = 1;
    }

    int sq = (int) sqrt (n);

    for (int i = 3; i <= sq; i += 2) {
        if (mark[i] == 0) {
            for (int j = i * i; j < n; j += (2 * i) ) {
                mark[j] = 1;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (mark[i] == 0) prime.pb (i);
    }
}

void prime_factorize (ll n) {
    int sq = (int) sqrt (n) + 1;

    for (int i = 0; i < (int) prime.size() && prime[i] <= sq; i++) {
        int cnt = 0;

        while (n % prime[i] == 0) {
            cnt++;
            n /= prime[i];
        }

        if (cnt != 0) fact.pb ({prime[i], cnt});
        sq = (int) sqrt (n);
    }

    if (n != 1) {
        fact.pb ({n, 1});
    }
}

void find_div (ll n, int i) {
    for (int j = i; j < (int) fact.size(); j++) {
        ll x = fact[j].first * n;

        for (int k = 0; k < (int) fact[j].second; k++) {
            di.pb (x);
            find_div (x, j + 1);
            x = x * fact[j].first;
        }
    }
}


int main () {
    //~ __FastIO;
    sieve (MAX);
    //~ cout << setprecision (10);
    //~ cout << fixed;
    int tc;
    ll a, b, L;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> a >> b >> L;
        ll lc = lcm (a, b);
        prime_factorize (L);
        find_div (1, 0);
        di.pb (1);
        sort (all (di) );
        ll c = -1;

        for (ll v : di) {
            ll tmp = lcm (v, lc);

            if (tmp == L) {
                c = v;
                break;
            }
        }
        cout << "Case " << t << ": ";

        if (c == -1) {
            cout << "impossible\n";

        } else {
            cout << c << "\n";
        }

        fact.clear(), di.clear();
    }

    return 0;
}
