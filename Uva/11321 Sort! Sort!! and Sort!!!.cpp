/***************************************************
 * Problem name : 11321 Sort! Sort!! and Sort!!!.cpp
 * Problem Link : https://uva.onlinejudge.org/external/113/11321.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
 * Problem Type : Adhoc
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
struct SortAr {
    ll num, mod;
};
bool cmp(SortAr a, SortAr b) {
    if (a.mod == b.mod) {
        if (a.num % 2 != 0 && b.num % 2 == 0) {
            return true;
        } else if (a.num % 2 == 0 && b.num % 2 != 0) {
            return false;
        } else if (a.num % 2 != 0 && b.num % 2 != 0) {
            return a.num > b.num;
        } else {
            return a.num < b.num;
        }
    } else return a.mod < b.mod;
}
int main () {
    ll n, m;
    while (scanf("%lld %lld", &n, &m) == 2) {
        if (n == 0 && m == 0) {
            printf("0 0\n");
            break;
        }
        SortAr ar[n + 3];
        for (ll i = 0 ; i < n; i++) {
            ll x;
            scanf("%lld", &x);
            ar[i].num = x;
            ar[i].mod = x % m;
        }
        sort(ar, ar + n, cmp);
        printf("%lld %lld\n", n, m);
        for (ll i = 0; i < n; i++) {
            printf("%lld\n", ar[i].num);
        }
    }
    return 0;
}
