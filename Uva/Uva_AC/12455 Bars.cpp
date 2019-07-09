/***************************************************
 * Problem Name : 12455 Bars.cpp
 * Problem Link : https://uva.onlinejudge.org/external/124/12455.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-07-09
 * Problem Type : Basic Recursion(I use DP)
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
int W, n, ar[23];
int dp[23][1003];
int fun (int i, int sum) {
    if (i >= n) {
        if (sum == W) return 1;
        else return 0;
    }

    if (dp[i][sum] != -1) return dp[i][sum];

    int res1 = 0, res2 = 0;

    if (sum + ar[i] <= W) {
        res1 = fun (i + 1, sum + ar[i]);
    }

    res2 = fun (i + 1, sum);
    return dp[i][sum] = res1 | res2;
}
int main () {
    __FastIO;			
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> W >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        if (W == 0) {
            cout << "YES\n";
            continue;
        }

        SET (dp, -1);
        int ans = fun (0, 0);

        if (ans == 1) {
            cout << "YES\n";

        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
