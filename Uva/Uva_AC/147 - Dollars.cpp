/***************************************************
 * Problem Name : 147 - Dollars.cpp
 * Problem Link : https://uva.onlinejudge.org/external/1/147.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-02-06
 * Problem Type : dp
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
#define MAX 100005
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
ll coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll ar[11][300003];
ll fun (ll n) {
    for (int i = 0; i < 11; i++) {
        ar[i][0] = 1;
    }

    for (int i = 5; i <= n; i++) {
        ar[0][i] = 1;
    }

    for (int i = 1; i < 11; i++) {
        for (int j = 5; j <= n; j += 5) {
            if (coin[i] > j) {
                ar[i][j] = ar[i - 1][j];

            } else {
                ar[i][j] = (ar[i][j - coin[i]]) + ar[i - 1][j];
            }
        }
    }

    return ar[10][n];
}
int main () {
    __FastIO;
    double num;

    while ( cin >> num ) {
        if (num == 0.00) break;

        ll n = (ll) (num * 100.0 + .50);
        ll ans = fun (n);
        cout << right << setw (6) << setprecision (2) << fixed << num;
        cout << right << setw (17) << ans << "\n";
    }

    return 0;
}
