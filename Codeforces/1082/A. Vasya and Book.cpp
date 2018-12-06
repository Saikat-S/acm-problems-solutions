/***************************************************
 * Problem Name : A. Vasya and Book.cpp
 * Problem Link : https://codeforces.com/contest/1082/problem/A
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-12-04
 * Problem Type : Edu Round - A
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
#define INF 1000000003
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
    //~ __FastIO;
    int tc, n, x, y, d;
    cin >> tc;

    while (tc--) {
        cin >> n >> x >> y >> d;
        int xx = 0;

        if (y == x) {
            cout << "0\n";

        } else {
            int xx = abs (x - y);

            if (xx % d == 0) {
                cout << xx / d << "\n";

            } else {
                int mx1 = INF, mx2 = INF;
                int xx = y - 1;

                if (xx % d == 0) {
                    mx1 = xx / d;
                    mx1 += (x - 1) / d;

                    if ( (x - 1) % d != 0) mx1++;
                }

                xx = n - y;

                if (xx % d == 0) {
                    mx2 = xx / d;
                    mx2 += (n - x) / d;

                    if ( (n - x) % d != 0) mx2++;
                }

                int mn = min (mx1, mx2);

                if (mn == INF) cout << "-1\n";
                else cout << mn << "\n";
            }
        }
    }

    return 0;
}
