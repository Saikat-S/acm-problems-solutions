/***************************************************
 * Problem name : 11614 Etruscan Warriors Never Play Chess.cpp
 * Problem Link : https://uva.onlinejudge.org/external/116/11614.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-27
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
ll binarySearch(ull n) {
    if(n == 0) return 0;
    ll low = 1, high =  1500000000, ans, mid;
    while (high >= low) {
        mid = (high + low) / 2;
        ull chk = (mid * (mid + 1) / 2);
        if (chk == n) {
            ans = mid;
            break;
        } else if (chk < n) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}
int main () {
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    ll tc, n;
    scanf("%lld", &tc);
    for (ll t = 1; t <= tc; t++) {
        scanf("%lld", &n);
        printf("%lld\n", binarySearch(n));
    }

    return 0;
}

