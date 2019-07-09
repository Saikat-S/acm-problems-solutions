/***************************************************
 * Problem Name : 1032 - Fast Bit Calculations.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1032
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
vector<int>num;
ll dp[35][35][2][2];

ll digitDP (int pos, int cnt, int cur, int isChoto) {
    if (pos == n) {
        return cnt;
    }

    if (dp[pos][cnt][cur][isChoto] != -1) {
        return dp[pos][cnt][cur][isChoto];
    }

    int low = 0, high = 1;

    if (isChoto == 0) {
        high = num[pos];
    }

    ll ans = 0;

    for (int i = low; i <= high; i++) {
        int new_cnt = cnt;
        int new_cur = cur;
        int new_isChoto = isChoto;

        if (cur == 1 && i == 1) {
            new_cnt++;
            new_cur = 1;

        } else if ( i == 1) {
            new_cur = 1;

        } else if (i == 0) {
            new_cur = 0;
        }

        if (i < high) {
            new_isChoto = 1;
        }

        ans += (ll) digitDP (pos + 1, new_cnt, new_cur, new_isChoto);
    }

    return dp[pos][cnt][cur][isChoto] = ans;
}

ll solve (ll N) {
    num.clear();

    while (N > 0) {
        int rem = N % 2;
        num.pb (rem);
        N /= 2;
    }

    reverse (all (num) );
    n = (int) num.size();
    SET (dp, -1);
    ll ans = digitDP (0, 0, 0, 0);
    return ans;
}

int main () {
    //~ __FastIO;
    int tc;
    ll N;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> N;
        ll ans = solve (N);
        cout << "Case " << t << ": " << ans << "\n";
    }

    return 0;
}
