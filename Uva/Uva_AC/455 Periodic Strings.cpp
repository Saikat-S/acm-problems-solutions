/***************************************************
 * Problem name : 455 Periodic Strings.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/455.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2017-11-23                         
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 100
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
int fun(string str, string ss) {
    int cnt = 0;
    for (int i = 0; i < (int)str.size();) {
        if (str.substr(i, ss.size()) == ss) {
            cnt++;
            i += ss.size();
        } else {
            cnt = -1;
            break;
        }
    }
    return cnt;
}
int main () {
    string str;
    int tc;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++) {
        cin >> str;
        int sz = str.size();
        for (int i = 1; i <= sz; i++) {
            string ss = str.substr(0, i);
            int szz = ss.size();
            int cnt = fun(str, ss);
            if(cnt*szz == sz){
                printf("%d\n", szz);
                break;
            }
        }
        if ( t != tc) nl;
    }
    return 0;
}
