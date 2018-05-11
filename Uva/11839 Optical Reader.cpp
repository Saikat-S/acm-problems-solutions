/***************************************************
 * Problem name : 11839 Optical Reader.cpp
 * Problem Link : https://uva.onlinejudge.org/external/118/11839.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-23
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
#define MAX 6
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
    char ar[] = {'A', 'B', 'C', 'D', 'E'};
    while (scanf("%d", &n) == 1 && n != 0 ) {
        for (int k = 1; k <= n; k++) {
            int cnt = 0;
            char ch;
            for (int i = 0; i < 5; i++) {
                int x;
                scanf("%d", &x);
                if (x <= 127) {
                    cnt++;
                    ch = ar[i];
                }
            }
            if (cnt != 1) printf("*\n");
            else printf("%c\n", ch);
        }
    }
    return 0;
}

