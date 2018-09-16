/***************************************************
 * Problem name : B. Our Tanya is Crying Out Loud.cpp
 * OJ           :
 * Verdict      : Trying
 * Date         : 2018-02-24
 * Problem Type :
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
#define MAX 100000
#define INF 2000000005
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
    ll n, m, a, b;
    scanf("%lld %lld", &n, &m);
    a = n, b = m;
    //~ printf("%lld", 2*n);
    while (1) {
        if ( a == 0 || b == 0) break;
        else {
            if (a >= (2 * b)) {
                ll x = a / (2 * b);
                a = a - (x * (2 * b));
            } else {
                if (b >= (2 * a)) {
                    ll x = b / (2 * a);
                    b = b - (x * (2 * a));
                } else break;
            }
        }
    }
    printf("%lld %lld", a, b);
    return 0;
}
