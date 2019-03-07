/***************************************************
 * Problem Name : C. Trailing Loves (or L'oeufs?).cpp
 * Problem Link : https://codeforces.com/contest/1114/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-02-26
 * Problem Type : Number Theory(Div 2 - C)
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
#define MAX 1000005
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

vector<ll>prime, fact;
char ar[MAX];
void Seive (ll n) {
    ar[0] = ar[1] = 1;

    for (int i = 4; i <= n; i += 2) ar[i] = 1;

    prime.push_back (2);
    ll sq = sqrt (n);

    for (int i = 3; i <= sq; i++) {
        if (ar[i] == 0) {
            for (int j = i * i; j <= n; j += 2 * i) ar[j] = 1;
        }
    }

    for (int i = 3; i <= n; i++) {
        if (ar[i] == 0) prime.push_back (i);
    }
}
void factorize ( ll n ) {
    ll sqrtn = sqrt ( n );

    for ( int i = 0; i < (int) prime.size() && prime[i] <= sqrtn; i++ ) {
        //~ if(ar[n] == 0) break;
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                fact.pb (prime[i]);
            }

            sqrtn = sqrt ( n );
        }
    }

    if ( n != 1 ) {
        fact.pb (n);
    }
}


ll factPrime (ll n, ll p) {
    ll cnt = 0;
    ll x = n;

    while (x > 0) {
        cnt += x / p;
        x /= p;
    }

    return cnt;
}
int main () {
    //~ __FastIO;
    Seive (1000003);
    ll n, b;
    cin >> n >> b;
    set<ll>st;
    map<ll, ll>mp;
    factorize (b);

    for (int i = 0; i < (int) fact.size(); i++) {
        //~ cout << fact[i] << " ";
        st.insert (fact[i]);
        mp[fact[i]]++;
    }

    //~ nl;
    ll ans = 10e18;

    for (auto it = st.begin(); it != st.end(); it++) {
        ll x = *it;
        ll val = factPrime (n, x);
        //~ cout << val << " "<< mp[x] <<" -\n";
        val = val / mp[x];
        ans = min (ans, val);
    }

    cout << ans << "\n";
    return 0;
}
