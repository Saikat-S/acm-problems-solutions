/***************************************************
 * Problem Name : B. WOW Factor.cpp
 * Problem Link : https://codeforces.com/contest/1178/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-20
 * Problem Type : CF G. Round - B
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define MAX 1000005
#define INF 1000000000
#define MOD 1000000007
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
int cum[MAX];
int main () {
    __FastIO;
    string str;
    cin >> str;
    int n = (int) str.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'v') {
            cnt++;

        } else {
            cnt = 0;
        }

        if (i == 0) {
            cum[i] = 0;

        } else {
            if (cnt >= 2) {
                cum[i] = cum[i - 1] + 1;

            } else {
                cum[i] = cum[i - 1];
            }
        }
    }

    ll ans = 0LL;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'o') {
            ll x = cum[i];
            ll xx = cum[n - 1] - x;
            ans += (x * xx);
        }
    }

    cout << ans << "\n";
    return 0;
}
