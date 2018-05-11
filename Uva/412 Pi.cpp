/***************************************************
 * Problem name : 412 Pi.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/412.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-26
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
#define MAX 51
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
    int ar[MAX];
    while (scanf("%d", &n ) == 1 && n != 0) {
        int total = 0, pair = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ar[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                total++;
                if (__gcd(ar[i], ar[j]) == 1) {
                    pair++;
                }
            }
        }
        //~ printf("%d %d\n", total, pair);
        if (!pair) printf("No estimate for this data set.\n");
        else {
            double pi = sqrt((6.0 * double(total)) / double(pair));
            printf("%.6lf\n", pi);
        }
    }
    return 0;
}

