/***************************************************
 * Problem name : 10815 - Andy's First Dictionary.cpp
 * Problem Link : https://uva.onlinejudge.org/external/108/10815.pdf
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
    set<string>st;
    while (cin >> str) {
        int sz = str.size();
        //~ if(sz == 5) break;
        string s;
        for (int i = 0; i < sz; i++) {
            if (isalpha(str[i])) {
                //~ debug;
                s.push_back(tolower(str[i]));
            } else {
                st.insert(s);
                s.clear();
            }
        }
        if (s != "") st.insert(s);
    }
    set<string>::iterator it;
    for (it = st.begin(); it != st.end(); it++) {
        string ss = *it;
        if (ss.size() != 0) cout << ss << "\n";
        //~ cout << *it << '\n';
    }
    return 0;
}

