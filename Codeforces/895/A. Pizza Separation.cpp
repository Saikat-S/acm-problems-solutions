/***************************************************
 * Problem Name : A. Pizza Separation.cpp
 * Problem Link : http://codeforces.com/contest/895/problem/A
 * OJ           : Codeforces
 * Verdict      : AC(*)
 * Date         : 2018-07-23
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
int main () {
    __FastIO;
    int n;
    cin >> n;
    int ar[n + 3];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int ans = 360;

    for (int i = 0; i < n; i++) {
        int sum = ar[i];
        ans = min (ans, abs (2 * sum - 360) );

        for (int j = 1; j < n ; j++) {
            sum += ar[ (i + j) % n];
            ans = min (ans, abs (2 * sum - 360) );
        }
    }

    cout << ans << "\n";
    return 0;
}
