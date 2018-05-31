/***************************************************
 * Problem name : 10107  What is the Median?.cpp
 * Problem Link : https://uva.onlinejudge.org/external/101/10107.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
 * Problem Type : AdHoc(STL)
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
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sp printf(" ")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define pb push_back
#define MAX 100000
#define INF 1000000000
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
    int n;
    vector<int>V;
    while (scanf("%d", &n) == 1) {
        V.pb(n);
        sort(V.begin(), V.end());
        int sz = (int)V.size();
        if (sz == 1) {
            printf("%d\n", V[0]);
        } else if ( sz % 2 == 1) {
            printf("%d\n", V[sz / 2]);
        } else {
            printf("%d\n", (V[sz / 2] + V[sz / 2 - 1]) / 2);
        }
    }
    return 0;
}
