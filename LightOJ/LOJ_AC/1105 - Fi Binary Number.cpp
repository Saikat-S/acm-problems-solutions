/***************************************************
 * Problem Name : 1105 - Fi Binary Number.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1105
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
ll n;
ll c;
ll dp[53][2][2];
ll digitDP (int pos, int pre, int isSuru) {
    if (pos == 45) {
        if (isSuru == 1) {
            return 1LL;

        } else {
            return 0LL;
        }
    }

    ll &ans = dp[pos][pre][isSuru];

    if (ans != -1) return ans;

    ans = 0;

    for (int i = 0; i <= 1; i++) {
        if (pre == 1 && i == 1) continue;

        ans += digitDP (pos + 1, i, isSuru | (i > 0) );
    }

    return ans;
}

void print (int pos, int pre, int isSuru) {
    if (pos == 45) {
        return;
    }

    for (int i = 0; i <= 1; i++) {
        if (pre == 1 && i == 1) continue;

        ll cnt = digitDP (pos + 1, i, isSuru | (i > 0) );

        if (cnt >= c) {
            if (isSuru == 1 || (i > 0) ) {
                printf ("%d", i);
            }

            print (pos + 1, i, isSuru | (i > 0) );
            return;

        } else {
            c -= cnt;
        }
    }
}
int main () {
    //~ __FastIO;
    SET (dp, -1);
    digitDP (0, 0, 0);
    int tc;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%lld", &n);
        c = n;
        printf ("Case %d: ", t);
        print (0, 0, 0);
        printf ("\n");
    }

    return 0;
}
