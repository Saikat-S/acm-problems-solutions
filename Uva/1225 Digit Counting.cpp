/***************************************************
 * Problem name : 1225 Digit Counting.cpp
 * Problem Link : https://uva.onlinejudge.org/external/12/1225.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-25
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
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 11
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
    int tc, N, ar[MAX];
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &N);
        string str = "";
        for (int i = 1; i <= N; i++) {
            str += NumberToString(i);
        }
        SET(ar);
        int sz = str.size();
        for (int i = 0; i < sz; i++) {
            int num = (str[i] - '0');
            ar[num]++;
        }
        for (int i = 0; i <= 9; i++) {
            if (i != 0) printf(" ");
            printf("%d", ar[i]);
        }
        nl;

    }
    return 0;
}
