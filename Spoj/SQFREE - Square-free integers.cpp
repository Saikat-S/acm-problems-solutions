/***************************************************
 * Problem name : SQFREE - Square-free integers.cpp
 * Problem Link : http://www.spoj.com/problems/SQFREE/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2017-11-11
 * Problem Type : Number Theory
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
#define MAX 10000005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/************************************ Code Start Here ******************************************************/
ll MF[MAX +2];
char ar[MAX +2];
void  Mobius_Function(ll n) {
    ar[0] = ar[1] = 1;
    for (ll i   = 1; i < n; i++) MF[i] = 1;
    for (ll i = 2; i < n; i++) {
        if (ar[i] == 0) {
            MF[i] = -1;
            for (ll j = i + i; j < n; j += i) {
                if (j % (i * i) == 0)MF[j] = 0;
                ar[j] = 1;
                MF[j] = (-1) * MF[j];
            }
        }
    }
}
vector<ll>mob;
void preCal(ll n) {
    //~ ll sq = sqrt(n);
    Mobius_Function(n);
    for (ll i = 2 ; i < n; i++) {
        if (MF[i] != 0) {
            mob.push_back(i);
        }
    }
}
int main () {
    preCal(MAX);
    ll tc, n;
    scanf("%lld", &tc);
    for (ll t = 1; t <= tc; t++) {
        scanf("%lld", &n);
        ll sq = sqrt(n);
        ll ans = n;
        for (ll i = 0; mob[i] <= sq; i++) {
            ll x = n/(mob[i]*mob[i]);
            ans+=(MF[mob[i]] * x);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
