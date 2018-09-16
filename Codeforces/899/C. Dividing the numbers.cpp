/***************************************************
 * Problem Name : C. Dividing the numbers.cpp
 * Problem Link : http://codeforces.com/contest/899/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-28
 * Problem Type : Div 2 - C
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
    vector<int>v;
    ll A = 0, B = 0;

    if (n > 3) {
        for (int i = n; i >= 1; i--) {
            if (A == B) {
                A += i;
                v.pb (i);

            } else if (A > B) {
                B += i;

            } else {
                A += i;
                v.pb (i);
            }
        }

        sort (all (v) );
        cout << abs (A - B) << "\n" << (int) v.size() << " ";

        for (int i = 0; i < (int) v.size(); i++) cout << v[i] << " ";

        nl;

    } else if (n == 3) cout << "0\n2 1 2\n";
    else cout << "1\n1 1\n";

    return 0;
}
