/***************************************************
 * Problem name : A.cpp
 * OJ           : Codeforses
 * Verdict      : AC
 * Date         : 2018-02-24
 * Problem Type : Div 2 - A
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
#define MAX 105
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
ll gcd (ll a, ll b) {
    if (a % b == 0) return b;

    return gcd (b, a % b);
}
ll lcm (ll a, ll b) {
    return a * b / gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
int main () {
    int n, d;
    cin >> n >> d;
    int ar[n + 3];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort (ar, ar + n);
    int mn = 1000;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                int x = ar[i] - ar[j];

                if (x <= d) {
                    int xx = (i - j + 1);
                    xx = n - xx;
                    mn = min (mn, xx);
                }
            }
        }
    }

    if (mn == 1000 && n == 1) mn = 0;
    else if (mn == 1000 && n != 1) mn = n - 1;

    cout << mn << "\n";
    return 0;
}
