/***************************************************
 * Problem Name : 1068 - Investigation.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1068
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
int n;
ll k;
ll dp[20][190][2][2][103];
vector<int>A, B;
ll digitDP (int pos, int sum, int isChoto, int isBoro, ll num) {
    if (pos == n) {
        if (sum % k == 0 && num == 0) return 1LL;
        else return 0;
    }

    if ( dp[pos][sum][isChoto][isBoro][num] != -1) {
        return dp[pos][sum][isChoto][isBoro][num];
    }

    int low = 0, high = 9;
    ll ans  = 0;

    if (isChoto == 0) high = B[pos];

    if (isBoro == 0) low = A[pos];

    for (int i = low; i <= high; i++) {
        ans += digitDP (pos + 1, sum + i, isChoto || (i < high), isBoro
                        || (i > low), ( (num * 10LL ) + i) % k );
    }

    return dp[pos][sum][isChoto][isBoro][num] = ans;
    return ans;
}

ll solve (ll a, ll b) {
    A.clear(), B.clear();

    while (b > 0) {
        int rem = b % 10;
        B.pb (rem);
        b /= 10;
    }

    reverse (all (B) );

    while (a > 0) {
        int rem = a % 10;
        A.pb (rem);
        a /= 10;
    }

    n = (int) B.size();

    while ( (int) A.size() < n) {
        A.pb (0);
    }

    reverse (all (A) );
    SET (dp, -1);
    ll ans = digitDP (0, 0, 0, 0, 0);
    return ans;
}

int main () {
    //~ __FastIO;
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        ll a, b;
        cin >> a >> b >> k;

        if (k > 82) {
            cout << "Case " << t << ": " << 0 << "\n";

        } else {
            ll ans = solve (a, b);
            cout << "Case " << t << ": " << ans << "\n";
        }
    }

    return 0;
}
