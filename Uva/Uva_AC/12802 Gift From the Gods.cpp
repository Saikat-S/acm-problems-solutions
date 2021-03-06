/***************************************************
 * Problem name : 12802 Gift From the Gods.cpp
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 29.06.2017
 * Problem Type : AdHoc
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
/************************************ Code Start Here ******************************************************/
int prime(ll n) {
    int i;
    if (n < 2)return 0;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0)return 0;
    }
    return 1;

}
int rev(ll n) {
    int revv = 0;
    while (n != 0) {
        revv = revv * 10;
        revv = revv + n % 10;
        n = n / 10;
    }
    return revv;
}

int main() {
    ll n;
    while (1) {
        scanf("%lld", &n);
        printf("%lld\n", 2 * n);
        if (rev(n) == n) {
            if (prime(rev(n)))
                break;
        }
    }
}

