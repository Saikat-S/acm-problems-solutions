/***************************************************
 * Problem Name : 378 - Intersecting Lines.cpp
 * Problem Link : https://uva.onlinejudge.org/external/3/378.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-07-17
 * Problem Type : Geometry
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<iomanip>
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
    int tc;
    cin >> tc;
    cout << "INTERSECTING LINES OUTPUT\n";

    for (int t = 1; t <= tc; t++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int a = - (y1 - y2);
        int b = x1 - x2;
        int c = (x1 * y2) - (x2 * y1);
        int aa = - (y3 - y4);
        int bb = x3 - x4;
        int cc = (x3 * y4) - (x4 * y3);
        double ans = (a * bb) - (b * aa);

        if (ans != 0) {
            double x = (double) (c * bb - b * cc) / ans;
            double y = (double) (a * cc - c * aa) / ans;
            cout << "POINT " << fixed << setprecision (2) << x << " " << y << "\n";

        } else if (a * x3 + b * y3 - c == 0) {
            cout << "LINE\n";

        } else {
            cout << "NONE\n";
        }
    }

    cout << "END OF OUTPUT\n";
    return 0;
}
