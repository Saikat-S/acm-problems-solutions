/***************************************************
 * Problem name : 231 Testing the CATCHER .cpp
 * Problem Link : https://uva.onlinejudge.org/external/2/p231.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 14.06.2017
 * Problem Type : LDS(DP)
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
int L[MAX];
int LIS(int n, vector<int>ar) {
    for (int i = 0; i < n; i++) {
        L[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ar[j] < ar[i]) {
                if (L[j] < L[i] + 1) {
                    L[j] = L[i] + 1;
                }
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (mx < L[i]) {
            mx = L[i];
        }
    }
    return mx;
}
int main () {
    vector<int>V;
    int x , t = 1;
    while (scanf("%d", &x) == 1 && x != -1) {
        V.push_back(x);
        while (scanf("%d", &x) == 1 && x != -1) {
            V.push_back(x);
        }
        int n = V.size();

        int result = LIS(n, V);
        if (t != 1) printf("\n");
        printf("Test #%d:\n", t++);
        printf("  maximum possible interceptions: %d\n", result);
        //~ if (t != 1) printf("\n");
        V.clear();
    }
    return 0;
}

