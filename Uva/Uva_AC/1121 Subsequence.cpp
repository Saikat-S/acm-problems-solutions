/***************************************************
 * Problem name : 1121 Subsequence.cpp
 * Problem Link : https://uva.onlinejudge.org/external/11/1121.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-19
 * Problem Type : Two Pointer
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
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 100003
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
    ll ar[MAX], N, S, ans;
    while (scanf("%lld %lld", &N, &S) == 2) {
        for (int i = 0; i < N; i++) {
            scanf("%lld", &ar[i]);
        }
        ll sum = 0, mn = 100005;
        for (int L = 0, R = 0; R <= N; ) {
            sum = sum + ar[R];
            if (S <= sum) {
                while (sum  <= S) {
                    ans = ( R - L ) + 1;
                    mn = min(mn, ans);
                    sum = sum - ar[L];
                    L++;
                }
            }
            R++;
        }
        if(mn == 100005) mn = 0;
        printf("%lld\n", mn);
        SET(ar);
    }

    return 0;
}

