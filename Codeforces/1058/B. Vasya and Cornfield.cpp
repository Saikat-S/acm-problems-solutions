/***************************************************
 * Problem Name : B. Vasya and Cornfield.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-23
 * Problem Type :
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
#define Pow2(x) ((x)*(x))
#define Mod(x, m) ((((x) % (m)) + (m)) % (m))
#define Max3(a, b, c) max(a, max(b, c))
#define Min3(a, b, c) min(a, min(b, c))
#define pb push_back
#define mk make_pair
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
float area (int x1, int y1, int x2, int y2,
            int x3, int y3) {
    return abs ( (x1 * (y2 - y3) + x2 * (y3 - y1) +
                  x3 * (y1 - y2) ) / 2.0);
}

bool check (int x1, int y1, int x2, int y2, int x3,
            int y3, int x4, int y4, int x, int y) {
    float A = area (x1, y1, x2, y2, x3, y3) +
              area (x1, y1, x4, y4, x3, y3);
    float A1 = area (x, y, x1, y1, x2, y2);
    float A2 = area (x, y, x2, y2, x3, y3);
    float A3 = area (x, y, x3, y3, x4, y4);
    float A4 = area (x, y, x1, y1, x4, y4);
    return (A == A1 + A2 + A3 + A4);
}
int main () {
    //~ __FastIO;
    int d, n, m;
    cin >> n >> d >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if (check (0, d, d, 0, n, n - d, n - d, n, x, y) ) {
            cout << "YES\n";

        } else cout << "NO\n";
    }

    return 0;
}
