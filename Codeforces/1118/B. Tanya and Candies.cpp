/***************************************************
 * Problem Name : B. Tanya and Candies.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : Trying
 * Date         : 2019-02-19
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
#define MAX 200005
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
int main () {
    //~ __FastIO;
    int n;
    cin >> n;
    ll ar[MAX];
    ll sum[2][MAX];
    sum[0][0] = 0;
    sum[1][0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];

        //~ sum[i % 2][i] = sum[i % 2][i - 1] + ar[i];
        if (i % 2 == 0) {
            sum[0][i] = sum[0][i - 1] + ar[i];
            sum[1][i] = sum[1][i - 1];

        } else {
            sum[1][i] = sum[1][i - 1] + ar[i];
            sum[0][i] = sum[0][i - 1];
        }

        //~ sum[0][i] = sum[i % 2][i - 1] + ar[i];
        //~ sum[i % 2][i] = sum[i % 2][i - 1] + ar[i];
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        ll odd = sum[1][i];
        ll even = sum[0][i];

        if (i % 2 == 0) {
            ll x = even - ar[i];
            ll X1 = sum[0][n] - sum[0][i];
            ll X2 = sum[1][n] - sum[1][i];
            ll S1 = x + X2;
            ll S2 = odd + X1;

            if (S1 == S2) cnt++;

        } else {
            ll x = odd - ar[i];
            ll X1 = sum[0][n] - sum[0][i];
            ll X2 = sum[1][n] - sum[1][i];
            ll S1 = x + X1;
            ll S2 = even + X2;

            if (S1 == S2) cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
