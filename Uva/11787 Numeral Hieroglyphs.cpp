/***************************************************
 * Problem name : 11787 Numeral Hieroglyphs.cpp
 * Problem Link : https://uva.onlinejudge.org/external/117/11787.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-26
 * Problem Type : ADHoc
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
map<char, ll> mp, chk;
void pre() {
    mp['B'] = 1 , mp['U'] = 10, mp['S'] = 100, mp['P'] = 1000, mp['F'] = 10000, mp['T'] = 100000, mp['M'] = 1000000;
}
int main () {
    pre();
    int n;
    string str;
    scanf("%d", &n);
    for (int q = 1; q <= n; q++) {
        cin >> str;
        ll ans = 0;
        int sz = str.size(), flag = 0, ck = 0;
        ll a = mp[str[0]];
        for (int i = 1; i < sz; i++) {
            if (mp[str[i]] > a && ck == 0) {
                ck = 1;
            } else if (mp[str[i]] < a && ck == 0) {
                ck = 2;
            }
            if (ck == 1) {
                if (mp[str[i]] < a) {
                    flag = 1;
                    break;
                } else a = mp[str[i]];
            } else if (ck == 2) {
                if (mp[str[i]] > a) {
                    flag = 1;
                    break;
                } else a = mp[str[i]];
            }
        }
        if (flag) printf("error\n");
        else {
            flag = 0;
            for (int i = 0; i < sz; i++) {
                ans += mp[str[i]];
                chk[str[i]]++;
                if (chk[str[i]] > 9) {
                    flag = 1;
                    break;
                }
            }
            if (flag) printf("error\n");
            else printf("%lld\n", ans);
        }
        chk.clear();
    }
    return 0;
}

