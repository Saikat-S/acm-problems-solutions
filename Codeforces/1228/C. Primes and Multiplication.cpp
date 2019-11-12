/***************************************************
 * Problem Name : C. Primes and Multiplication.cpp
 * Problem Link : https://codeforces.com/contest/1228/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-09-29
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
vector<int>prime, di;
char ch[MAX];

void seive() {
    ch[1] = 1;

    for (int i = 4; i < MAX; i += 2) {
        ch[i] = 1;
    }

    int sq = sqrt (MAX);

    for (int i = 1; i <= sq; i++) {
        if (ch[i] == 0) {
            for (int j = i + i; j < MAX; j += i) {
                ch[j] = 1;
            }
        }
    }

    for (int i = 2; i < MAX; i++) {
        if (ch[i] == 0) prime.pb (i);
    }
}

void fact (int n) {
    int sq = sqrt (n);

    for (int i = 0; i <= sq && i <= prime[i]; i++) {
        if (n % prime[i] == 0) {
            while (n % prime[i] == 0) {
                n /= prime[i];
            }

            di.pb (prime[i]);
        }
    }

    if (n > 1) {
        di.pb (n);
    }

    sort (all (di) );
}

ll bigMod (ll n, ll b) {
    if (b == -1) b = MOD - 2;

    ll res = 1;

    while (b) {
        if (b & 1) res = (res * n) % MOD;

        n = (n * n) % MOD, b >>= 1;
    }

    return res;
}
int main () {
    __FastIO;
    //~ cout << setprecision (10);
    //~ cout << fixed;
    seive();
    int x;
    ll n;
    cin >> x >> n;
    fact (x);
    ll ans = 1;

    for (int i = 0; i < (int) di.size(); i++) {
        ll tmp = 0;
        ll num = n;

        while (num > 0) {
            tmp = (tmp + (num / di[i]) );
            num /= di[i];
        }

        ll sum = bigMod (di[i], tmp);
        ans = (ans * sum) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
