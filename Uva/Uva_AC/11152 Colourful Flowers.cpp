/***************************************************
 * Problem name : 11152 Colourful Flowers.cpp
 * Problem Link : https://uva.onlinejudge.org/external/111/11152.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 13.06.2017
 * Problem Type : Geometry
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
#define pi acos(-1)
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
int main () {
    double a, b, c;
    double S, p, r, R, S1, S2, S3;
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        p = (a + b + c) * 0.5;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        R = a * b * c / 4 / S;
        r = sqrt((p - a) * (p - b) * (p - c) / p);

        S1 = pi * R * R - S;
        S3 = pi * r * r;
        S2 = S - S3;

        printf("%.4f %.4f %.4f\n", S1, S2, S3);
    }
    return 0;
}

