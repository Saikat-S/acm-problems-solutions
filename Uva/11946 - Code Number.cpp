/***************************************************
 * Problem name : 11946 - Code Number.cpp
 * Problem Link : https://uva.onlinejudge.org/external/119/11946.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 14.06.2017
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
/************************************ Code Start Here ******************************************************/
char code(char ch) {
    if (ch == '4') return 'A';
    else if (ch == '8') return 'B';
    else if (ch == '3') return 'E';
    else if (ch == '6') return 'G';
    else if (ch == '1') return 'I';
    else if (ch == '0') return 'O';
    else if (ch == '9') return 'P';
    else if (ch == '5') return 'S';
    else if (ch == '7') return 'T';
    else  if (ch == '2') return 'Z';
    else return ch;
}
int main () {
    int tc;
    string str;
    scanf("%d", &tc);
    getchar();
    for (int t = 1; t <= tc; t++) {
        while (getline(cin, str)) {
            int l = str.size();
            if (l == 0) break;
            for (int i = 0; i < l; i++) {
                cout << code(str[i]);
            }
            nl;
        }
        if(t!=tc) nl;
    }
    return 0;
}

