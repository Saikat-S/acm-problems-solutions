/***************************************************
 * Problem name : 10684 The jackpot.cpp
 * Problem Link : https://uva.onlinejudge.org/external/106/10684.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 31.05.2017
 * Problem Type : Maximum Sum
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
#define MAX 10005
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

int kadane(int ar[], int N) {
    int sum = 0, mx = INT_MIN;
    for (int i = 0; i < N; i++) {
        sum = sum + ar[i];
        if (sum  < 0) sum = 0;
        if (mx < sum) mx = sum;
    }
    return mx;
}
int main () {
    int N, ar[MAX];
    while (scanf("%d", &N) == 1 && N != 0) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &ar[i]);
        }
        int mx = kadane(ar, N);
        if (mx > 0) {
            printf("The maximum winning streak is %d.\n", mx);
        } else {
            printf("Losing streak.\n");
        }
    }
    return 0;
}

