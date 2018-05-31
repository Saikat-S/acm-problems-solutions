/***************************************************
 * Problem name : 499 - What's The Frequency, Kenneth?.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/499.pdf
 * OJ           : Uva
 * Verdict      : Ac
 * Date         : 2017-08-04
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
#define MAX 300
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
map<char, int>mp, chk;
//~ int mp[MAX], chk[MAX];
int main () {
    string str;
    while (getline(cin, str)) {
        int sz = str.size();
        for (int i = 0; i < sz; i++) {
            if (isalpha(str[i])) {
                mp[str[i]]++;
            }
        }
        int mx = 0;
        map<char, int> :: iterator it;
        for ( it = mp.begin(); it != mp.end(); it++) {
            mx = max(mx, it->second);
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            if (mx == it->second && chk[it->first] == 0) {
                cout << it->first;
                chk[it->first] = 1;
            }
        }
        printf(" %d\n", mx);
        mp.clear(), chk.clear();
    }
    return 0;
}

