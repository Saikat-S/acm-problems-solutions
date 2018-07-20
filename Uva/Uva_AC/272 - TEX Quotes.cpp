/***************************************************
 * Problem name : 272 - TEX Quotes.cpp
 * Problem Link : https://uva.onlinejudge.org/external/2/272.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 13.06.2017
 * Problem Type : String
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
int main () {
    ll count = 0;
    string s;
    while (getline(cin, s)) {
        ll l = s.size();
        for (ll i = 0; i < l; i++) {
            if (s[i] == '"') {
                count = count + 1;
                if (count % 2 == 1)
                    printf("``");
                else
                    printf("''");
            } else
                printf("%c", s[i]);
        }
        nl;
    }
    return 0;
}

