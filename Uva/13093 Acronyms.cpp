/***************************************************
 * Problem name : 13093 Acronyms.cpp
 * Problem Link : https://uva.onlinejudge.org/external/130/13093.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2017-10-31                         
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
    string a, b,tmp;
    while(getline(cin, a)){
        getline(cin, b);
        map<string, int>mp;
        string str, str1;
        stringstream ss;
        ss << a;
        while(ss>>tmp){
            str.push_back(tmp[0]);
        }
        ss.clear();
        ss << b;
        while(ss>>tmp){
            str1.push_back(tmp[0]);
        }
        if(str == str1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

