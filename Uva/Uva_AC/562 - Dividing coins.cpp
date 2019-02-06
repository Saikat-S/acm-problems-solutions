/***************************************************
 * Problem Name : 562 - Dividing coins.cpp
 * Problem Link : https://uva.onlinejudge.org/external/5/562.pdf
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
#define MAX 505
#define INF 1000000000
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
int ar[MAX];
int n, need;
int dp[103][25003];

int coin_change (int i, int make) {
    if (i >= n) {
        return make;
    }

    if (dp[i][make] != -1) return dp[i][make];

    int ret1 = 0, ret2 = 0;

    if ( (make + ar[i] <= need) ) {
        ret1 = coin_change (i + 1, make + ar[i]);
    }

    ret2 = coin_change (i + 1, make);
    return dp[i][make] = max (ret1, ret2);
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        int sum = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            sum += ar[i];
        }

        need = sum / 2;
        SET (dp, -1);
        int ans = coin_change (0, 0);
        cout << (sum - (2 * ans) ) << "\n";
    }

    return 0;
}
