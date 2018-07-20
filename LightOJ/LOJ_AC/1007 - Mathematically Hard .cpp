/***************************************************
 * Problem name : 1007 - Mathematically Hard .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1007                       
 * OJ           : LOJ                                  
 * Verdict      : AC                      
 * Date         : 2017-11-02                         
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
#define MAX 5000006
//~ #define MAX 11
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
//~ vector<ll>prime;
//~ char ar[MAX];
//~ ll sum[MAX], arr[MAX];
//~ ll arr[MAX];
//~ void seive(ll n) {
//~ ar[0] = ar[1] = 1;
//~ prime.push_back(2);
//~ for (ll i = 4; i <= n; i += 2) {
//~ ar[i] = 1;
//~ }
//~ ll sq = sqrt(n);
//~ for (ll i = 3; i <= sq; i += 2) {
//~ if (ar[i] == 0) {
//~ for (ll j = i * i; j <= n; j += 2 * i) {
//~ ar[j] = 1;
//~ }
//~ }
//~ }
//~ for (ll i = 3; i <= n; i++) {
//~ if (ar[i] == 0) prime.push_back(i);
//~ }
//~ }
ull Q[MAX];
//~ ll sum[MAX];
void seive(ull n) {
    Q[1] = 0;
    for (ull i = 2; i < n; i++) {
        Q[i] = i;
    }
    //~ ll sq = sqrt(n);
    for (ull i = 2; i < n; i++) {
        //~ if (ar[i] == 0) {
        if (Q[i] == i) {
            for (ull j = i; j < n; j += i) {
                //~ Q[j] /= i;
                //~ Q[j] *= i - 1;
                Q[j] = Q[j] * (i - 1) / i;
                //~ ar[j] = 1;
            }
        }
    }
    //~ for (ll i = 2; i <= n; i++) {
    //~ if (ar[i] == 0) {
    //~ Q[i] = i - 1;
    //~ }
    //~ }
}
//~ ll eulerPhi ( ll n ) {
//~ ll res = n;
//~ ll sqrtn = sqrt ( n );
//~ for ( ll i = 0; i < (ll)prime.size() && prime[i] <= sqrtn; i++ ) {
//~ if ( n % prime[i] == 0 ) {
//~ while ( n % prime[i] == 0 ) {
//~ n /= prime[i];
//~ }
//~ sqrtn = sqrt ( n );
//~ res /= prime[i];
//~ res *= prime[i] - 1;
//~ }
//~ }
//~ if ( n != 1 ) {
//~ res /= n;
//~ res *= n - 1;
//~ }
//~ return res;
//~ }
void preCal() {
    seive(MAX);
    //~ sum[1] = 0;
    for (ull i = 2; i < MAX; i++) {
        //~ cout << i << "= " << Q[i] << "\n";
        //~ sum[i] = sum[i - 1] + Q[i] * Q[i];
        Q[i] = Q[i - 1] + Q[i] * Q[i];
    }
}
int main () {
    preCal();
    int tc;
    ull a, b;
    scanf("%d", &tc);
    //~ printf("%lld\n", arr[tc]);
    for (int t = 1; t <= tc; t++) {
        scanf("%llu %llu", &a, &b);
        //~ ll ans = 0;
        //~ for(int i = a; i<=b; i++){
        //~ ans+=(Q[i]*Q[i]);
        //~ }
        printf("Case %d: %llu\n", t, Q[b] - Q[a - 1]);
        //~ printf("%lld\n",Q[a]);
    }
    return 0;
}

