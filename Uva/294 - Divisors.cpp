/***************************************************
 * Problem name : 294 - Divisors.cpp
 * Problem Link : https://uva.onlinejudge.org/external/2/294.pdf                       
 * OJ           : Uva                                  
 * Verdict      : Ac                      
 * Date         : 2017-07-28                         
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
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 100000
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
ll prime[MAX], arr[MAX], cnt, len, sum[MAX];
void sieve(ll N) {
    ll i, j;
    cnt = 0;
    len = sqrt(N);
    for (i = 2; i <= len; i++) {
        if (arr[i] == 0) {
            for (j = i + i; j <= N; j += i) {
                arr[j] = 1;
            }
        }
    }
    for (i = 2; i <= N; i++) {
        if (arr[i] == 0) {
            prime[cnt++] = i;
        }
    }
}
ll divisor(ll n) {
    ll i, divN = 1, c;
    len = sqrt(n);
    for (i = 0; i < cnt && prime[i] <= len; i++) {
        if (n % prime[i] == 0) {
            c = 0;
            while (n % prime[i] == 0) {
                c++;
                n /= prime[i];
            }
            divN *= (c + 1);
        }
    }
    if (n > 1) divN *= 2;

    return divN;
}
int main () {
    ll tc, a, b;
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &a, &b);
        ll N = sqrt(b);
        sieve(N);
        ll mx = 0, ans;
        for (ll i = a; i <= b; i++) {
            ll NumberOfDivisor = divisor(i);
            if (NumberOfDivisor > mx) {
                mx = NumberOfDivisor;
                ans = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", a, b, ans, mx);
    }

    return 0;
}
