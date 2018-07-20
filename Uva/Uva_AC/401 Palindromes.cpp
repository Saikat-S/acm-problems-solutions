/***************************************************
 * Problem name : 401 Palindromes.cpp
 * Problem Link : https://uva.onlinejudge.org/external/4/401.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-04
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
char isMirror(char ch) {
    if (ch == 'A') return 'A';
    else if (ch == 'E') return '3';
    else if (ch == 'H') return 'H';
    else if (ch == 'I') return 'I';
    else if (ch == 'J') return 'L';
    else if (ch == 'L') return 'J';
    else if (ch == 'M') return 'M';
    else if (ch == 'O') return 'O';
    else if (ch == 'S') return '2';
    else if (ch == 'T') return 'T';
    else if (ch == 'U') return 'U';
    else if (ch == 'V') return 'V';
    else if (ch == 'W') return 'W';
    else if (ch == 'X') return 'X';
    else if (ch == 'Y') return 'Y';
    else if (ch == 'Z') return '5';
    else if (ch == '1') return '1';
    else if (ch == '2') return 'S';
    else if (ch == '3') return 'E';
    else if (ch == '5') return 'Z';
    else if (ch == '8') return '8';

    return 'a';
}
bool isM(string str) {
    //~ int flag = 0;
    string rev = "";
    for (int i = 0; i < (int)str.size() ; i++) {
        char ch = isMirror(str[i]);
        if (ch == 'a') return 0;
        rev += ch;
    }
    reverse(rev.begin(), rev.end());
    if (str == rev)return 1;

    return 0;
}
int main () {
    __FastIO;
    string str;
    while (cin >> str) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        if (rev == str) {
            if (isM(str)) {
                cout << str << " -- is a mirrored palindrome.\n";
            } else cout << str << " -- is a regular palindrome.\n";
        } else {
            if (isM(str)) {
                cout << str << " -- is a mirrored string.\n";
            } else cout << str << " -- is not a palindrome.\n";
        }
        cout << "\n";
    }

    return 0;
}
