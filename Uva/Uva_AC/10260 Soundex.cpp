/***************************************************
 * Problem name : 10260 Soundex.cpp
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 09.06.2017
 * Problem Type : AdHoc
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
char Number(char ch) {
    if (ch == 'B' || ch == 'F' || ch == 'P' || ch == 'V') return '1';
    else if (ch == 'C' || ch == 'G' || ch == 'J' || ch == 'K' || ch == 'Q' || ch == 'S' || ch == 'X' || ch == 'Z') return '2';
    else if (ch == 'D' || ch == 'T') return '3';
    else if (ch == 'L') return '4';
    else if (ch == 'M' || ch == 'N') return '5';
    else if (ch == 'R') return '6';
    else return '0';
}
int main () {
    string str;

    while (cin >> str) {
        int sz = str.size();
        char flag = '0';
        string code;
        for (int i = 0; i < sz; i++) {
            char n = Number(str[i]);
            if(n != '0'){
				if(n != flag){
					code+=n;
					flag = n;
				}
			}
			else if(n == '0') flag = '0';
        }
        cout << code;
        nl;
    }
    return 0;
}

