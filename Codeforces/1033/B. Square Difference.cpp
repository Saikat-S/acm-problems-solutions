/***************************************************
 * Problem Name : B. Square Difference.cpp
 * Problem Link : https://codeforces.com/contest/1033/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-10-08
 * Problem Type : Number Theory (AdHoc)
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
bool isPrime (ll a, ll b) {
    if ( (a - b) != 1) return false;

    ll n = a + b;
    ll sq = (ll) sqrt (n);

    for (int i = 2; i <= sq; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        ll a, b;
        cin >> a >> b;

        if (isPrime (a, b) ) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
