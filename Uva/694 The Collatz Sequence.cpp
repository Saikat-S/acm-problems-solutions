/***************************************************
 * Problem name : 694 The Collatz Sequence.cpp
 * Problem Link : https://uva.onlinejudge.org/external/6/694.pdf
 * OJ           : Uva
 * Verdict      : Ac
 * Date         : 2017-08-02
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
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    ll A, L,t = 1;
    while (scanf("%lld %lld", &A, &L) == 2 && (A > 0 || L > 0)) {
        ll n = A, cnt = 0;
        while (n<=L && n != 1) {
            if (n % 2 == 0) n = n / 2;
            else n = 3 * n + 1;
            cnt++;
        }
        if (n == 1) cnt++;
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",t++,  A, L, cnt);
    }

    return 0;
}

