/***************************************************
 * Problem Name : NUMTSN - 369 Numbers.cpp
 * Problem Link : https://www.spoj.com/problems/NUMTSN/en/
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
ll dp[53][53][53][53][3][3];
vector<int>A, B;
ll digitDp (int pos, int cnt3, int cnt6, int cnt9, int isChoto, int isBoro) {
    if (pos == n) {
        if (cnt3 != 0 && cnt3 == cnt6 && cnt6 == cnt9) return 1;
        else return 0;
    }

    if (dp[pos][cnt3][cnt6][cnt9][isChoto][isBoro] != -1 && isChoto == 1
        && isBoro == 1) {
        return dp[pos][cnt3][cnt6][cnt9][isChoto][isBoro];
    }

    ll ans = 0;
    int low = 0, high = 9;

    if (isChoto == 0) {
        high = B[pos];
    }

    if (isBoro == 0) {
        low = A[pos];
    }

    for (int i = low; i <= high; i++) {
        int new_cnt3 = cnt3;
        int new_cnt6 = cnt6;
        int new_cnt9 = cnt9;
        int new_isChoto = isChoto;
        int new_isBoro = isBoro;

        if (i == 3) new_cnt3++;

        if (i == 6) new_cnt6++;

        if (i == 9) new_cnt9++;

        if (i < high) {
            new_isChoto = 1;
        }

        if (i > low)     {
            new_isBoro = 1;
        }

        ans = (ans + ( (ll) digitDp (pos + 1, new_cnt3, new_cnt6, new_cnt9,
                                     new_isChoto, new_isBoro) % MOD) ) % MOD;
    }

    return dp[pos][cnt3][cnt6][cnt9][isChoto][isBoro] = ans % MOD;
}

ll solve (string a, string b) {
    A.clear(), B.clear();
    int x = 51 - (int) a.size();

    for (int i = 0; i < x; i++) {
        A.pb (0);
    }

    x = 51 - (int) b.size();

    for (int i = 0; i < x; i++) {
        B.pb (0);
    }

    for (int i = 0; i < (int) b.size(); i++) {
        B.pb (b[i] - '0');
    }

    for (int i = 0; i < (int) a.size(); i++) {
        A.pb (a[i] - '0');
    }

    n = (int) B.size();
    ll ans = digitDp (0, 0, 0, 0, 0, 0);
    return ans;
}


int main () {
    __FastIO;
    int tc;
    cin >> tc;
    SET (dp, -1);

    for (int t = 1; t <= tc; t++) {
        string a, b;
        cin >> a >> b;
        ll ans = solve (a, b);
        cout << ans << "\n";
    }

    return 0;
}
