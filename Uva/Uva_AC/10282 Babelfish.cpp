/***************************************************
 * Problem name : 10282 Babelfish.cpp
 * Problem Link : https://uva.onlinejudge.org/external/102/10282.pdf
 * OJ           : Uva
 * Verdict      : AC
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
map<string, string>mp;
int main () {
    string str;
    while (getline(cin, str)) {
        int sz = str.size();
        if (sz == 0) break;
        int flag = 0;
        string a, b;
        for (int i = 0; i < sz; i++) {
            if (str[i] == ' ') {
                flag = 1;
            } else {
                if (flag == 0) {
                    a += str[i];
                } else b += str[i];
            }
        }
        mp[b] = a;
        //~ cout << a  << " " << b ;
        //~ nl;
    }
    string s;
    while(cin >> s){
        if(mp[s].size() == 0){
            cout << "eh\n";
        }
        else cout << mp[s]<<"\n";
    }

    return 0;
}

