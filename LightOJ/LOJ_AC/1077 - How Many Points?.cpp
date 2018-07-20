/***************************************************
 * Problem name : 1077 - How Many Points?.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1077
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-10-25
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
//~ ll gcd(ll a, ll b) {
    //~ if (a % b == 0) return b;
    //~ return gcd(b, a % b);
//~ }
//~ ll lcm(ll a, ll b) {
    //~ return a * b / gcd(a, b);
//~ }
/************************************ Code Start Here ******************************************************/
//~ int gcd(int a, int b) {
    //~ while (b) {
        //~ a = a % b;
        //~ swap(a, b);
    //~ }
    //~ return a;
//~ }
int main () {
    ll tc, x1, x2, y1, y2, x, y;
    scanf("%lld", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        x = abs(x1 - x2);
        y = abs(y1 - y2);
        printf("Case %d: %lld\n", t, __gcd(x, y) + 1);
    }
    return 0;
}

