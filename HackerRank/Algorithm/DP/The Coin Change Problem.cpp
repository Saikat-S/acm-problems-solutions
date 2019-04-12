/***************************************************
 * Problem Name : The Coin Change Problem.cpp
 * Problem Link : https://www.hackerrank.com/challenges/coin-change/problem
 * OJ           : HackerRank
 * Verdict      : AC
 * Date         : 2019-04-04
 * Problem Type : dp(coin change)
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
#define MAX 53
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
int coin[MAX];
int need, m;
ll dp[MAX][253];
ll coin_change (int i, int store) {
    if (i == m) {
        if (store == need) {
            return 1LL;

        } else {
            return 0LL;
        }
    }

    ll &ans = dp[i][store];

    if (ans != -1) return ans;

    ll res1 = 0LL, res2 = 0LL;
    ans = 0;

    if (store + coin[i] <= need) {
        res1 = coin_change (i, store + coin[i]);
    }

    res2 = coin_change (i + 1, store);
    return ans = (res1 + res2);
}

int main () {
    //~ __FastIO;
    cin >> need >> m;

    for (int i = 0; i < m; i++) {
        cin >> coin[i];
    }

    SET (dp, -1);
    ll ans = coin_change (0, 0);
    cout << ans << "\n";
    return 0;
}
