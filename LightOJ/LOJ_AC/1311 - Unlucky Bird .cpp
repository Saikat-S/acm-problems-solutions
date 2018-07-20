/***************************************************
 * Problem name : 1311 - Unlucky Bird .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1311
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-11-08
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
int main() {
    int tc;
    double v1, v2, v3, a1, a2;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++) {
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
        double t1 = v1 / a1;
        double t2 = v2 / a2;
        double t = max(t1, t2);
        double ans = t * v3;
        double dis = v1 * t1 + 0.5 * - a1 * t1 * t1;
        dis += (v2 * t2 + 0.5 * -a2 * t2 * t2);
        printf("Case %d: %.9lf %.9lf\n", i, dis, ans);

    }
    return 0;
}

