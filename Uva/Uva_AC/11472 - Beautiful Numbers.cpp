/***************************************************
 * Problem Name : 11472 - Beautiful Numbers.cpp
 * Problem Link : https://uva.onlinejudge.org/external/114/11472.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-07-09
 * Problem Type : Digit DP
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
int n, m;
ll dp[103][11][1030];
vector<int>vec;
ll digitDP (int pos, int pre, int mask) {
    if (pos == m) {
        return 0LL;
    }

    ll &ans = dp[pos][pre][mask];

    if (ans != -1) return ans;

    ans = 0;
    int high = n - 1;

    for (int i = 0; i <= high; i++) {
        if (abs (pre - i) == 1 || (pos == 0 && i != 0) ) {
            int new_mask = mask;
            new_mask = new_mask | (1 << i);
            int cnt = __builtin_popcount (new_mask);

            if (cnt == n) {
                ans = (ans + (1LL + digitDP (pos + 1, i, new_mask) ) ) % MOD;

            } else {
                ans = (ans + digitDP (pos + 1, i, new_mask) ) % MOD;
            }
        }
    }

    return ans;
}

ll solve () {
    SET (dp, -1);
    ll ans = digitDP (0, 0, 0);
    return ans;
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        ll ans = solve ();
        cout << ans << "\n";
    }

    return 0;
}
