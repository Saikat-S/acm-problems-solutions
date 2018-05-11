/***************************************************
 * Problem name : 11876 - N + NOD (N).cpp
 * Problem Link : https://uva.onlinejudge.org/external/118/11876.pdf
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
#define MAX 1000003
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
map<ll, bool>mp;
void sieve() {
    ll i, j;
    cnt = 0;
    len = sqrt(MAX);
    for (i = 2; i <= len; i++) {
        if (arr[i] == 0) {
            for (j = i + i; j < MAX; j += i) {
                arr[j] = 1;
            }
        }
    }
    for (i = 2; i < MAX; i++) {
        if (arr[i] == 0) {
            prime[cnt++] = i;
        }
    }
}
ll divisor(ll n) {
    if (n == 0) return 0;
    ll i, divN = 1, c;
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
void PreCal() {
    ll k = 1, x = 1, cnt;
    mp[x] = true;
    while (x <= MAX) {
        x = k + divisor(k);
        mp[x] = true;
        k = x;
    }
    sum[0] = 0, cnt = 0;
    for (int i = 1; i <= MAX; i++) {
        if (mp[i] == true) cnt++;

        sum[i] = cnt;
    }
}
int main () {
    ll tc, a, b;
    sieve();
    PreCal();
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &a, &b);
        ll ans;
        if (mp[a] == true) ans = (sum[b] - sum[a]) + 1;
        else ans = sum[b] - sum[a];
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}

