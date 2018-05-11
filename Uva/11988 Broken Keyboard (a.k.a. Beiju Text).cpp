/***************************************************
 * Problem name : 11988 Broken Keyboard (a.k.a. Beiju Text).cpp
 * Problem Link : https://uva.onlinejudge.org/external/119/11988.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-05-05
 * Problem Type : String(STL)
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
int main () {
    string str;
    while (getline(cin, str)) {
        string braket = "", ans = "", khali = "";
        int f = 0;
        str.pb(']');
        vector<string>faul;
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] != '[' && str[i] != ']') {
                khali += str[i];
            } else {
                if (f == 0) {
                    for (int j = 0; j < (int)khali.size(); j++) {
                        ans.pb(khali[j]);
                    }
                    khali.clear();
                } else {
                    faul.push_back(khali);
                    khali.clear();
                }

                if (str[i] == '[') f = 1;
                else f = 0;
            }
        }
        reverse(faul.begin(), faul.end());
        for (int i = 0; i < (int)faul.size(); i++) {
            braket += faul[i];
        }
        cout << braket + ans; nl;
    }
    return 0;
}
