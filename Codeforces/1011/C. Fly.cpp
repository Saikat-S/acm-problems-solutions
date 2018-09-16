/***************************************************
 * Problem Name : C. Fly.cpp
 * Problem Link : http://codeforces.com/contest/1011/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-07-26
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
#include<iomanip>
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
#define MAX 1005
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
int ar[MAX], br[MAX];
int n, m;
bool check (double val) {
    double sum = val;

    for (int i = 0; i < n; i++) {
        double S = (double) m + sum ;
        double x = S / (double) ar[i];
        sum = sum - x;

        if (sum < 0) return 0;

        if (i  < n) {
            S = (double) m + sum;
            x = S / (double) br[i];
            sum = sum - x;
        }

        if (sum < 0) return 0;
    }

    if (sum < 0) return 0;
    else return 1;
}
double binary () {
    double low = 0.0, high = 1000000005, mid;

    for (int i = 0; i < 200; i++) {
        mid = (high + low) / 2.0;

        if (check (mid) ) {
            high  = mid;

        } else low = mid;
    }

    if (mid > 1000000000) return -1;

    return mid;
}
int main () {
    __FastIO;
    cin >> n >> m;

    for (int i = 0; i < n ; i++) {
        cin >> ar[i];
    }

    for (int i = 0; i < n ; i++) {
        cin >> br[i];
    }

    if (binary() == -1) cout << "-1\n";
    else cout << fixed << setprecision (15) << binary() << "\n";

    return 0;
}
