/***************************************************
 * Problem Name : A. Mr. Kitayuta's Gift.cpp
 * Problem Link : http://codeforces.com/contest/505/problem/A
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2018-07-11
 * Problem Type : Div 2 - A
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SET(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define pll pair <ll, ll>
#define debug cout <<"#########\n";
#define nl cout << "\n";
#define sp cout << " ";
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pf(n) scanf("%d", n)
#define pfl(n) scanf("%lld", n)
#define all(v) v.begin(), v.end()
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
ll lcm (ll a, ll b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
bool isPalindrome (string str) {
    string tmp = str;
    reverse (all (tmp) );

    if (tmp == str) return true;
    else return false;
}
int main () {
    __FastIO;
    string str;
    cin >> str;
    //~ string s = str;

    for (int i = 0; i <=(int) str.size(); i++) {
        for (int ch = 'a'; ch <= 'z'; ch++) {
            string s = str.substr (0, i);
            string ss = str.substr (i, (int) str.size() - i);
            string S = s += ch;
            S += ss;

            if (isPalindrome (S) ) {
                cout << S << "\n";
                return 0;
            }

            //~ cout << S << " " << ss << " \n";
            //~ break;
        }

        //~ break;
    }

    cout << "NA\n";
    return 0;
}
