/***************************************************
 * Problem Name : C. NN and the Optical Illusion.cpp
 * Problem Link : https://codeforces.com/contest/1100/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-01-13
 * Problem Type : Div 2 - C
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<iomanip>
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
#define PI acos(-1.0)
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
double binary (double n, double r) {
    double low = 0.0, high = 1000000000.0;
    double ans, mid;

    for (int i = 0; i < 500; i++) {
        mid = (low + high) / 2.0;
        double a = r + mid;
        double b = a;
        double c = mid + mid;
        double C = acos ( (Pow2 (a) + Pow2 (b) - Pow2 (c) ) / (2.0 * a * b) );
        C = (C * 180.0) / PI;

        if ( (360.0 / C) <= n) {
            ans = mid;
            high = mid;

        } else {
            low = mid;
        }
    }

    return ans;
}
int main () {
    //~ __FastIO;
    double n, r;
    cin >> n >> r;
    double ans = binary (n, r);
    cout << setprecision (7) << fixed;
    cout << ans << "\n";
    return 0;
}
