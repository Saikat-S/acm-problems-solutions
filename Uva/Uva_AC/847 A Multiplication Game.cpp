/***************************************************
 * Problem name : 847 A Multiplication Game.cpp
 * Problem Link : https://uva.onlinejudge.org/external/8/847.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-10
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
#define MAX 100005
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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    //~ __FastIO;
    ll n;
    while (scanf("%lld", &n) == 1) {
        ll sum = 1, ans;
        for (int i = 1; ; i++) {

            if (i % 2 == 1) {
                if (sum * 9 >= n) {
                    ans = i; break;
                } else {
                    sum *= 9;
                }
            } else {
                if (sum * 2 >= n) {
                    ans = i; break;
                } else {
                    sum *= 2;
                }
            }

        }
        if (ans % 2 == 1) {
            printf("Stan wins.\n");
        } else {
            printf("Ollie wins.\n");
        }
    }
    return 0;
}
