/***************************************************
 * Problem Name : CPCRC1C - Sum of Digits.cpp
 * Problem Link : https://www.spoj.com/problems/CPCRC1C/en/
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
int n;
ll dp[20][100][2][2];
vector<int>A, B;
ll digitDP (int pos, int cnt,  int isChoto, int isBoro) {
    if (pos == n) {
        return cnt;
    }

    if (dp[pos][cnt][isChoto][isBoro] != -1) {
        return dp[pos][cnt][isChoto][isBoro];
    }

    ll ans = 0;
    int high, low;

    if (isChoto == 0) {
        high = B[pos];

    } else {
        high = 9;
    }

    if (isBoro == 0) {
        low = A[pos];

    } else {
        low = 0;
    }

    for (int i = low; i <= high; i++) {
        int new_cnt = cnt;
        int new_isChoto = isChoto;
        int new_isBoro = isBoro;
        new_cnt += i;

        if (i < high) {
            new_isChoto = 1;
        }

        if (i > low)     {
            new_isBoro = 1;
        }

        ans += (ll) digitDP (pos + 1, new_cnt,  new_isChoto, new_isBoro);
    }

    return dp[pos][cnt][isChoto][isBoro] = ans;
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
    ll ans = digitDP (0, 0, 0, 0);
    return ans;
}

int main () {
    __FastIO;
    ll a, b;

    while (cin >> a >> b) {
        if (a == -1 && b == -1) break;

        ll ans  = solve (a, b);
        cout << ans << "\n";
    }

    return 0;
}
