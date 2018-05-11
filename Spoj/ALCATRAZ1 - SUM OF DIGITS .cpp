/***************************************************
 * Problem name : ALCATRAZ1 - SUM OF DIGITS .cpp
 * Problem Link : http://www.spoj.com/problems/ALCATRAZ1/
 * OJ           : Spj
 * Verdict      : AC
 * Date         : 2017-10-07
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
    ll sum;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++) {
        string str;
        cin >> str;
        sum = 0;
        int sz = str.size();
        for (int i = 0; i < sz; i++) {
            sum += (str[i] - '0');
        }
        printf("%lld\n", sum);
    }
    return 0;
}

