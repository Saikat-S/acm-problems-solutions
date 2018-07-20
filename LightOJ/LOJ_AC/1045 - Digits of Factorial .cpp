/***************************************************
 * Problem name : 1045 - Digits of Factorial .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1045
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
#define MAX 1000006
//~ #define MAX 16
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
//~ ll NumberOfdigitFact(ll n,ll b){
//~ double x = 0;
//~ for(int i = 1; i<=n; i++){
//~ x+= log10 (i) /log10 (b);
//~ }
//~ ll ans = ((ll) x) + 1;
//~ return ans;
//~ }
double ar[MAX];
//~ ll NumberOfdigitFact(ll n) {
//~ double x = 0;
//~ for (int i = 1; i <= n; i++) {
//~ x  = log10 (n);
//~ }
//~ ll ans = ((ll) x);
//~ debug;
//~ return ans;
//~ }
void preCal() {
    ar[0] = 1;
    double sum = 0;
    for (int i = 1; i <= MAX; i++) {
        sum += log10(i);
        ar[i] = sum;
        //~ printf("%lld %lld %lld\n", i, ar[i], x);
        //~ debug;
    }
    //~ debug;
}
ll baseConvert(double n, ll b) {
    ll ans = n / (log10 (b));
    return ans + 1;
}
int main () {
    preCal();
    //~ printf("jhafjwejfrgsejfj\n");
    ll tc, n, b;
    scanf("%lld", &tc);
    //~ printf("%lld\n", baseConvert(tc, 16));
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &n, & b);
        printf("Case %d: %lld\n", t, baseConvert(ar[n], b));
    }

    return 0;
}

