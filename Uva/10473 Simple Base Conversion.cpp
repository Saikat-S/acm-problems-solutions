/***************************************************
 * Problem name : 10473 Simple Base Conversion.cpp
 * Problem Link : https://uva.onlinejudge.org/external/104/10473.pdf#page=1&zoom=160,-20,833
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2017-07-25
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
ll pow(ll n) {
    if (n == 0) return 1;
    ll sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= 16;
    }
    return sum;
}
ll stringToNum(string str){
    ll num  = 0, sz = str.size();
    for(int i = 0; i<sz; i++){
        num = (num *10) + (str[i]-'0');
    }
    return num;
}
ll hexaTodeci(string str) {
    ll sz = str.size(),num = 0, n;
    for(int i  = sz-1, j = 0; i>=2; i--, j++){
        if(str[i] == 'A') n = 10;
        else if(str[i] == 'B') n = 11;
        else if(str[i] == 'C') n = 12;
        else if(str[i] == 'D') n = 13;
        else if(str[i] == 'E') n = 14;
        else if(str[i] == 'F') n = 15;
        else n = (str[i] - '0');
        
        num+=(pow(j) * n);
    }
    return num;
}
int main () {
    string str;
    while (cin >> str) {
        if (str[0] == '-') break;
        if (str[0] == '0' && str[1] == 'x') {
            //~ cout << hexaTodeci(str) << "\n";
            printf("%lld\n", hexaTodeci(str));
        } else {
            printf("0x%X\n", stringToNum(str));
        }
    }
    return 0; 
}

