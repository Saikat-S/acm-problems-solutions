/***************************************************
 * Problem name : Separate the Numbers.cpp
 * Problem Link : https://www.hackerrank.com/challenges/separate-the-numbers/problem
 * OJ           : HackerRank
 * Verdict      : Trying
 * Date         : 2018-05-03
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
ll stringToNum(string str) {
    ll num  = 0;
    int sz = str.size();
    for (int i = 0; i < sz; i++) {
        num = (num * 10) + (str[i] - '0');
    }
    return num;
}
int main () {
    int tc;
    string str;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        cin >> str;
        vector<string>V[MAX];
        for (int i = 0; i < (int)str.size(); i++) {
            string st = str.substr(0, i + 1);
            //~ V[i].pb(s);
            
            for (int j = i+1; j < (int)str.size(); j++) {
                string s = str.substr(j, i + 1);
                //~ V[i].pb(s);
            }
        }
        //~ for(int i = 0; ; i++){
            //~ if((int)V[i].size() == 0) break;
            //~ for(int j  = 0; j<(int)V[i].size(); j++){
                //~ cout << V[i][j] <<" ";
            //~ }
            //~ nl;
        //~ }
    }

    return 0;
}
