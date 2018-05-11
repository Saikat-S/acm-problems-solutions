/***************************************************
 * Problem name : 11889 - Benefit.cpp
 * Problem Link : https://uva.onlinejudge.org/external/118/11889.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-29
 * Problem Type : AdHoc
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
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
vector<ll>divs;
//~ ll gcd(ll a, ll b) {
//~ if (a % b == 0)
//~ return b;
//~ return gcd(b, a % b);
//~ }
//~ ll lcm(ll a, ll b) {
//~ return a * b / gcd(a, b);
//~ }
void Divisors(ll n) {
    ll len = sqrt(n);
    for (ll i = 1; i <= len; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (n % (n / i) == 0) {
                divs.push_back(n / i);
            }
        }

    }
}
int main () {
    ll tc, A, C;
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &A, &C);
        if (C % A != 0) {
            printf("NO SOLUTION\n");
            continue;
        }
        Divisors(C);
        sort(divs.begin(), divs.end());
        int sz = divs.size();
        for (int i = 0; i < sz; i++) {
            //~ printf("%lld ", divs[i]);
            int lc = lcm(A, divs[i]);
            if (lc == C) {
                printf("%lld\n", divs[i]);
                break;
            }
        }
        divs.clear();
    }
    return 0;
}

