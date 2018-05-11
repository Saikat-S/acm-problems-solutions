/***************************************************
 * Problem name : 11577 Letter Frequency.cpp
 * Problem Link : https://uva.onlinejudge.org/external/115/11577.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-21
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
#define MAX 1000
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
int mp[MAX];
//~ map<char, int>mp;
int main () {
    int tc;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++) {
        string str;
        getline(cin, str);
        int sz = str.size();
        for (int i = 0; i < sz; i++) {
            char ch = str[i];
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + 32;
                }
                mp[ch]++;
            }
        }
        //~ map<char, int>::iterator it;
        int mx = 0;
        //~ for (it = mp.begin(); it != mp.end(); it++) {
            //~ int x = it->second;
            //~ mx = max(x, mx);
        //~ }
        //~ for (it = mp.begin(); it != mp.end(); it++) {
            //~ int x = it->second;
            //~ if (x == mx) printf("%c", it->first);
        //~ }
        //~ nl;
        for(int i = 97; i<=123; i++){
            mx = max(mx, mp[i]);
        }
        for(int i = 97; i<=123; i++){
            if(mp[i] == mx)
            printf("%c", i);
        }
        nl;
        SET(mp);
        //~ mp.clear();
    }
    return 0;
}

