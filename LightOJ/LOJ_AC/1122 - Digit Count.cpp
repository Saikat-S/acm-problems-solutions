/***************************************************
 * Problem Name : 1122 - Digit Count.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1122
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-07-09
 * Problem Type : DigitDP
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
int m, n;
int ar[13];
ll dp[13][13];
int digitDP (int pos, int num) {
    if (pos == n) {
        return 1;
    }

    if (dp[pos][num] != -1) {
        return dp[pos][num];
    }

    ll ans = 0;

    for (int i = 0; i < m; i++) {
        if (num == 0 || abs (ar[i] - num) <= 2) {
            ans += digitDP (pos + 1, ar[i]);
        }
    }

    return dp[pos][num] = ans;
}
int main () {
    //~ __FastIO;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> m >> n;

        for (int i = 0; i < m; i++) {
            cin >> ar[i];
        }

        SET (dp, -1);
        ll ans = 0;
        ans = digitDP (0, 0);
        cout << "Case " << t << ": " << ans << "\n";
    }

    return 0;
}
