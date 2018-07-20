/***************************************************
 * Problem name : 11057 Exact Sum.cpp
 * Problem Link : https://uva.onlinejudge.org/external/110/11057.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-25
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
#define MAX 10003
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
    ll N, M, ar[MAX];
    map<ll, int>mp;
    //~ ll mp[MAX];
    while (scanf("%lld", &N) == 1) {
        //~ SET(mp);
        for (int i = 0; i < N; i++) {
            scanf("%lld", &ar[i]);
            mp[ar[i]] = 1;
        }
        scanf("%lld", &M);
        sort(ar, ar + N);
        ll a, b, mn = 10000000;
        for (int i = 0; i < N; i++) {
            ll ans = M - ar[i];
            ll dif = abs(ans - ar[i]);
            if (mp[ans] == 1 && (dif < mn)) {
                a = ar[i];
                b = ans;
                mn = dif;
            }
        }
        printf("Peter should buy books whose prices are %lld and %lld.\n", a, b);
        nl;
        mp.clear();
    }
    return 0;
}

