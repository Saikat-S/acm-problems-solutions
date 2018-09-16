/***************************************************
 * Problem Name : B. Minimum Ternary String.cpp
 * Problem Link : http://codeforces.com/contest/1009/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-21
 * Problem Type : Educational - B
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
int main () {
    __FastIO;
    string str;
    cin >> str;
    int one = 0;
    int flag = 0;

    for (int i = 0; i < (int) str.size(); i++) {
        if (str[i] == '1') one++;
        else if (str[i] == '2') flag = 1;
    }

    string ans = "";

    if (!flag) {
        for (int i = 0; i < (int) str.size(); i++) {
            if (str[i] != '1') ans += str[i];
        }

        for (int i = 0; i < one; i++) {
            ans += '1';
        }

    } else {
        int f = 1;

        for (int i = 0; i < (int) str.size(); i++) {
            if (str[i] == '2' && f ) {
                f  = 0 ;

                for (int j = 0; j < one; j++) {
                    ans += '1';
                }

                ans += '2';

            } else if (str[i] != '1') ans += str[i];
        }
    }

    cout << ans << "\n";
    return 0;
}
