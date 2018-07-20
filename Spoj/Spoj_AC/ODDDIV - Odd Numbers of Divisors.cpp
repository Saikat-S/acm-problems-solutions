/***************************************************
 * Problem name : ODDDIV - Odd Numbers of Divisors.cpp
 * Problem Link : http://www.spoj.com/problems/ODDDIV/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2017-11-12
 * Problem Type : Number Theory
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
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
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
vector<ll>V[MAX];
ll Lower(ll k, ll value) {
    ll high = V[k].size()-1, low = 0, ans = -1;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (V[k][mid] == value) {
            return mid;
        } else if (V[k][mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == -1) {
        ans = high;
    }
    return ans;
}
ll Upper(ll k, ll value) {
    ll mid, high = V[k].size()-1, low = 0, ans = -1;
    while (high >= low) {
        mid = (high + low) / 2;
        if (V[k][mid] == value) {
            return mid;
        } else if (V[k][mid] > value) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == -1) {
        ans = low;
    }
    return ans;
}
vector<ll> prime;
char sieve[MAX];
void primeSieve (ll n) {
    sieve[0] = sieve[1] = 1;
    prime.push_back(2);
    for ( ll i = 4; i < n; i += 2 ) sieve[i] = 1;
    ll sqrtn = sqrt ( n );
    for ( ll i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( ll j = i * i; j < n; j += 2 * i ) sieve[j] = 1;
        }
    }
    for ( ll i = 3; i < n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}
ll NOD(ll n) {
    ll sqrtn = sqrt ( n );
    ll res = 1;
    for (ll i = 0; i < (ll)prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            ll p = 0;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p *= 2;
            p++;
            res *= p;
        }
    }
    if ( n != 1 ) {
        res *= 3;
    }
    return res;
}
void preCal() {
    //~ ll sum = 5;
    //~ for (ll i = 4; i <= MAX ;) {
    //~ V.push_back(i);
    //~ i = i + sum;
    //~ sum = sum + 2;
    //~ }
    for (ll i = 1; i < MAX; i++) {
        ll div = NOD(i);
        V[div].push_back(i * i);
    }
}
int main () {
    primeSieve(sqrt(MAX));
    preCal();
    ll tc, k, lo, hi;
    scanf("%lld", &tc);
    for (ll t = 1; t <= tc; t++) {
        scanf("%lld %lld %lld", &k, &lo, &hi);
        ll x = Upper(k, lo);
        ll y = Lower(k, hi);
        //~ ll x  = sqrt(lo), y = sqrt(hi);
        //~ printf("%lld %lld\n", x, y);
        ll cnt = y - x;
        //~ for (ll i = x; i <= y; i++) {
            //~ if (k == VV[i]) cnt++;
        //~ }
        printf("%lld\n", cnt+1);
    }
    return 0;
}
