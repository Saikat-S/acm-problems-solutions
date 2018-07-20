/***************************************************
 * Problem name : 481 What Goes Up.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/481.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 14.06.2017
 * Problem Type : DP(LIS)
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
ll L[MAX], I[MAX];
ll LIS_NlogK(ll n , vector<ll>ar) {
    I[0] = -100000000;
    //~ for (ll i = 1; i <= n; i++) {
        //~ I[i] = 100000000;
    //~ }
    ll Maxlen = 0;
    for (ll i = 0; i < n; i++) {
        ll low = 0, high = Maxlen, mid;
        while (high >= low) {
            mid = (low + high) / 2;
            if (I[mid] < ar[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        I[low] = ar[i];
        L[i] = low;
        if(Maxlen < low){
			Maxlen = low;
		}
    }
    return Maxlen;
}
void LIS_Solution(ll n, vector<ll>ar) {
    vector<ll>Sol;
    ll i = 0;
    for (ll j = 1 ; j < n; j++) {
        if (L[j] >= L[i]) {
            i = j;
        }
    }
    Sol.push_back(ar[i]);
    ll top = i;
    for (ll i = top - 1; i >= 0; i--) {
        if ( ar[i] < ar[top] && L[i] == L[top] - 1) {
            Sol.push_back(ar[i]);
            top = i;
        }
    }
    ll sz = Sol.size();
    for (ll i = sz - 1 ; i >= 0; i--) {
        printf("%lld\n", Sol[i]);
    }
    Sol.clear();
}
int main () {
    vector<ll>V;
    ll x;
    while (scanf("%lld", &x) != EOF) {
        V.push_back(x);
    }
    ll n = V.size();
    ll result = LIS_NlogK(n,V);
    printf("%lld\n", result);
    printf("-\n");
    LIS_Solution(n,V);
    V.clear();
    return 0;
}

