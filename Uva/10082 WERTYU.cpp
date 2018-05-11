/***************************************************
 * Problem name : 10082 WERTYU.cpp
 * Problem Link : https://uva.onlinejudge.org/external/100/10082.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
 * Problem Type : String
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
string mp = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char fun(char ch) {
    for (int i = 0; i < (int)mp.size(); i++) {
        if (mp[i] == ch) return mp[i - 1];
    }
    return ch;
}
int main () {
    __FastIO;
    string str;
    while (getline(cin, str)) {
        for (int i = 0; i < (int)str.size(); i++) {
            str[i] = fun(str[i]);
        }
        cout <<  str << "\n";
    }
    return 0;
}

