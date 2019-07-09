/***************************************************
 * Problem Name : GONE - G-One Numbers.cpp
 * Problem Link : https://www.spoj.com/problems/GONE/en/
 * OJ           : Spoj
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
vector<int>A, B;
int n;
ll dp[10][2][2][75];
bool isPrime (int n) {
    if (n == 0 || n == 1) return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

ll digitDP (int pos, int isChoto, int isBoro, int sum) {
    if (n == pos) {
        if (isPrime (sum) ) return 1LL;
        else return 0LL;
    }

    ll &ans = dp[pos][isChoto][isBoro][sum];

    if (ans != -1) return ans;

    int low = 0, high = 9;

    if (isChoto == 0) high = B[pos];

    if (isBoro == 0) low = A[pos];

    ans = 0;

    for (int i = low; i <= high; i++) {
        ans += digitDP (pos + 1, isChoto | (i < high), isBoro | (i > low), sum + i);
    }

    return ans;
}

ll solve (ll a, ll b) {
    A.clear(), B.clear();

    while (b > 0) {
        B.pb (b % 10);
        b /= 10;
    }

    while (a > 0) {
        A.pb (a % 10);
        a /= 10;
    }

    n = (int) B.size();

    while ( (int) A.size() < n) {
        A.pb (0);
    }

    reverse (all (A) );
    reverse (all (B) );
    SET (dp, -1);
    ll ans = digitDP (0, 0, 0, 0);
    return ans;
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        ll a, b;
        cin >> a >> b;
        ll ans  = solve (a, b);
        cout << ans << "\n";
    }

    return 0;
}

