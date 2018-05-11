/***************************************************
 * Problem name : 443 - Humble Numbers.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/443.pdf
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
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
vector<ll>hum;
int ar[4] = {2, 3, 5, 7};
map<ll, bool>mp;
void humNum(ll n) {
    if (n > 2000000000 || mp[n] == 1) return;
    hum.push_back(n);
    mp[n] = 1;
    for (int i = 0; i <= 3; i++) {
        humNum(n * ar[i]);
    }
}
int main () {
    ll n;
    humNum(1);
    sort(hum.begin(), hum.end());
    while (scanf("%lld", &n) == 1 && n != 0) {
        printf("The %lld", n);
        if (n % 10 == 1 && n % 100 != 11) printf("st");
        else if (n % 10 == 2 && n % 100 != 12) printf("nd");
        else if (n % 10 == 3 && n % 100 != 13) printf("rd");
        else printf("th");
        printf(" humble number is %lld.\n", hum[n - 1]);
    }
    return 0;
}
