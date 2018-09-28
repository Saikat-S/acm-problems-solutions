/***************************************************
 * Problem Name : B. Weakened Common Divisor.cpp
 * Problem Link : https://codeforces.com/contest/1025/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-28
 * Problem Type : Div. 1 + Div. 2 - B
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
#include<deque>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
#define MAX 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
set<int>vv;
vector<int> prime;
char sieve[MAX];
void primeSieve ( int n ) {
    sieve[0] =  sieve[1] = 1;
    prime.pb (2);

    for ( int i = 4; i <= n; i += 2 ) {
        sieve[i] = 1;
    }

    int sqrtn = sqrt ( n );

    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) {
                sieve[j] = 1;
            }
        }
    }

    for ( int i = 3; i <= n; i += 2 ) {
        if ( sieve[i] == 0 ) {
            prime.pb (i);
        }
    }
}
void fact ( int n ) {
    int sqrtn = sqrt ( n );

    for ( int i = 0; i < (int) prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                vv.insert (prime[i]);
            }

            sqrtn = sqrt ( n );
        }
    }

    if ( n != 1 ) {
        vv.insert (n);
    }
}
int main () {
    __FastIO;
    primeSieve (MAX);
    int n;
    cin >> n;
    vector<pii>v;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.pb (pii (x, y) );
    }

    fact (v[0].first);
    fact (v[0].second);
    int ans = -1;

    for (auto it = vv.begin(); it != vv.end(); it++) {
        int x = *it;
        bool f = 0;

        if (x != 1) {
            for (int i = 1; i < n; i++) {
                if (v[i].first % x == 0 || v[i].second % x == 0) {
                    continue;

                } else {
                    f = 1;
                    break;
                }
            }

            if (!f) {
                ans = x;
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
