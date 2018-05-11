/***************************************************
 * Problem name : 11878 Homework Checker.cpp
 * Problem Link : https://uva.onlinejudge.org/external/118/11878.pdf
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
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    string str;
    int cnt = 0;
    while (cin >> str) {
        int sz = str.size(), a = 0, b = 0, c = 0, i = 0, flag = 0;
        char  ch;
        while (str[i] != '+' && str[i] != '-') {
            a = (a * 10 ) +  (str[i] - '0');
            i++;
        }
        ch = str[i];
        i++;
        while (str[i] != '=') {
            b = (b * 10) + (str[i] - '0');
            i++;
        }
        i++;
        if (str[i] != '?') {
            while (i < sz) {
                c = (c * 10) + (str[i] - '0');
                i++;
            }
        } else {
            flag = 1;
        }
        int ans;
        if (ch == '+') ans = a + b;
        else if (ch == '-') ans = a - b;
        if (!flag && ans == c) cnt++;
        //~ printf("a = %d , b = %d , c = %d, ch = %c\n", a, b, c, ch);
    }
    printf("%d\n", cnt);
    return 0;
}

