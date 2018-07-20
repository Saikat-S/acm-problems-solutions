/***************************************************
 * Problem name : 10611 The Playboy Chimp.cpp
 * Problem Link : https://uva.onlinejudge.org/external/106/10611.pdf
 * OJ           : Uva
 * Verdict      : AC(Time = 1230ms)
 * Date         : 13.06.2017
 * Problem Type : AdHoc
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
#define MAX 50005
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
    ull n, Q, ar[MAX], x;
    scanf("%llu", &n);
    for (ull i = 0; i < n ; i++) scanf("%llu", &ar[i]);
    scanf("%llu", &Q);
    for (ull q = 1; q <= Q; q++) {
        scanf("%llu", &x);
        ull mn = 0;
        ull mx = 100000000000;
        for (ull i = 0; i < n; i++) {
            if (ar[i] < x && mn <= ar[i]) mn = ar[i];
            if (ar[i] > x && mx >= ar[i]) mx = ar[i];
        }
        if (mn == 0 && mx == 100000000000) printf("X X\n");
        else if (mn == 0 && mx != 100000000000) printf("X %llu\n", mx);
        else if (mn != 0 && mx == 100000000000) printf("%llu X\n", mn);
        else if (mn != 0 && mx != 100000000000) printf("%llu %llu\n", mn, mx);
    }
    return 0;
}
