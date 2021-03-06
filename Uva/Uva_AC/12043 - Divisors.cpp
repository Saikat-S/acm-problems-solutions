/***************************************************
 * Problem Name : 12043 - Divisors.cpp
 * Problem Link : https://onlinejudge.org/external/120/12043.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2020-08-17
 * Problem Type : NT
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
vector<int>prime;
char mark[MAX];

void sieve (int n) {
    int sq = (int) sqrt (n) + 1;
    mark[0] = mark[1] = 1;

    for (int i = 4; i < n; i += 2) {
        mark[i] = 1;
    }

    for (int i = 0; i <= sq; i += 2) {
        if (mark[i] == 0) {
            for (int j = i * i; j < n; j += (2 * i) ) {
                mark[j] = 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (mark[i] == 0) prime.pb (i);
    }
}

int nod (int n) {
    int cnt = 1;
    int sq = (int) sqrt (n);

    for (int i = 0; i < (int) prime.size() && prime[i] <= sq; i++) {
        int c = 0;

        while (n % prime[i] == 0) {
            c++;
            n /= prime[i];
        }

        sq = (int) sqrt (n);
        c++;
        cnt *= c;
    }

    if (n != 1) {
        cnt *= 2;
    }

    return cnt;
}


int sod (int n) {
    int sum = 1;
    int sq = (int) sqrt (n);

    for (int i = 0; i < (int) prime.size() && prime[i] <= sq; i++) {
        int c = 1;
        int res = 1;

        while (n % prime[i] == 0) {
            n /= prime[i];
            c *= prime[i];
            res += c;
        }

        sq = (int) sqrt (n);
        sum *= res;
    }

    if (n != 1) {
        sum *= (n + 1);
    }

    return sum;
}

int d[MAX], s[MAX];


void pre_cal() {
    for (int i = 1; i < MAX; i++) {
        d[i] = nod (i);
        s[i] = sod (i);
    }
}


int main () {
    __FastIO;
    //~ cout << setprecision (10) << fixed;
    sieve (MAX - 2);
    pre_cal();
    int tc;
    cin >> tc;

    while (tc--) {
        int a, b, k;
        cin >> a >> b >> k;

        if (a > b) swap (a, b);

        ll sum_d = 0;
        ll sum_s = 0;

        for (int i = a; i <= b; i++) {
            if (i % k == 0) {
                sum_d += (ll)d[i];
                sum_s += (ll)s[i];
            }
        }

        cout << sum_d << " " << sum_s << "\n";
    }

    return 0;
}
