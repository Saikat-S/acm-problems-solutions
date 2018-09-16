/***************************************************
 * Problem Name : B. Turn the Rectangles.cpp
 * Problem Link : http://codeforces.com/contest/1008/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-14
 * Problem Type : Div 2 - B
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
    int n;
    cin >> n;
    int flag = 0;
    int mx = 0;

    for (int i  = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;

        if (i != 0) {
            int m = max (w, h);

            if (m <= mx) {
                mx = m;

            } else {
                int mn = min (w, h);

                if (mn <= mx) {
                    mx = mn;

                } else {
                    flag = 1;
                }
            }

        } else {
            mx = max (w, h);
        }
    }

    if (flag) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
