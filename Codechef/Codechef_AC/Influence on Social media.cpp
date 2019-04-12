/***************************************************
 * Problem Name : Influence on Social media.cpp
 * Problem Link : https://www.codechef.com/problems/AMR16C
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2019-01-24
 * Problem Type : Number Theory (easy)
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
#define FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
vector<ll> prime;
char sieve[10000005];
void primeSieve ( ll n ) {
    sieve[0] = sieve[1] = 1;
    prime.push_back (2);

    for ( ll i = 4; i <= n; i += 2 ) {
        sieve[i] = 1;
    }

    ll sqrtn = sqrt ( n );

    for ( ll i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( ll j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 ) {
        if ( sieve[i] == 0 ) prime.push_back (i);
    }
}
ll NOD ( ll n ) {
    ll sqrtn = sqrt ( n );
    ll res = 1;

    for ( ll i = 0; i < (int) prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            ll p = 0;

            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p++;
            }

            sqrtn = sqrt ( n );
            p++;
            res *= p;
        }
    }

    if ( n != 1 ) {
        res *= 2;
    }

    return res;
}
struct st {
    ll id, val;
};

bool cmp (st a, st b) {
    return a.val > b.val;
}

int main () {
    //~ __FastIO;
    int tc, n;
    cin >> tc ;
    primeSieve (MAX);

    while (tc--) {
        st ar[MAX];
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i].val;
            ar[i].id = 0;
        }

        sort (ar, ar + n, cmp);
        vector<pii>vec;

        for (int i = 0; i < n; i++) {
            ll x = sqrt (ar[i].val);

            if (x * x == ar[i].val) {
                ll xx = NOD (ar[i].val);

                if (sieve[xx] == 0) {
                    vec.pb (pii (ar[i].id, i) );
                }
            }
        }

        if ( (int) vec.size() == 0) {
            cout << "No supporter found.\n";
            continue;
        }

        sort ( all (vec) );

        for (int i = 0; i < (int) vec.size(); i++) {
            if (i != 0) cout << " ";

            cout << vec[i].second + 1;
        }

        nl;
    }

    return 0;
}
