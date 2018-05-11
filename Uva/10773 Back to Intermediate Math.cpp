/***************************************************
 * Problem name : 10773 Back to Intermediate Math.cpp
 * Problem Link : https://uva.onlinejudge.org/external/107/10773.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2017-07-27                         
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
int main () {
    int tc;
    double d, u, v;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lf %lf %lf", &d, &v, &u);
        if(u == 0 || v == 0 || v>=u) printf("Case %d: can't determine\n", t);
        else {
            double short_time = (d*1.0)/(u*1.0);
            double short_path = (1.0* d)/((sqrt(u*u - v*v))*1.0);
            printf("Case %d: %.3lf\n", t, fabs(short_path - short_time));
        }
    }
    return 0;
}
