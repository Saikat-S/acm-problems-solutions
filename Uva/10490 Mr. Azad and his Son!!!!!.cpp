/***************************************************
 * Problem name : 10490 Mr. Azad and his Son!!!!!.cpp
 * Problem Link : https://uva.onlinejudge.org/external/104/10490.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 06.06.2017
 * Problem Type : Number Theory
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
#define MAX 35
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
//////////////////////////////////////////////////////////////////////////////////////
ll ar[MAX];
map<int, ll>mp;
void sieve() {
    ll sqrtMAX = sqrt(MAX);
    for (ll i = 2; i <= sqrtMAX; i++) {
        if (ar[i] == 0) {
            for (ll j = i + i; j <= MAX; j += i) {
                ar[j] = -1;
            }
        }
    }
}
void perfectNum() {
    mp[2] = 6;
    mp[3] = 28;
    mp[5] = 496;
    mp[7] = 8128;
    mp[13] = 33550336;
    mp[17] = 8589869056;
    mp[19] = 137438691328;
    mp[31] = 2305843008139952128;
}
int main () {
    sieve();
    perfectNum();
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        if (mp[n] != 0 ) {
            printf("Perfect: %lld!\n", mp[n]);
        } else {
            if (ar[n] == 0) {
                printf("Given number is prime. But, NO perfect number is available.\n");
            } else {
                printf("Given number is NOT prime! NO perfect number is available.\n");
            }
        }
    }
    return 0;
}

