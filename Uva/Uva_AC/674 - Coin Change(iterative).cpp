/***************************************************
 * Problem Name : 674 - Coin Change(iterative).cpp
 * Problem Link : https://uva.onlinejudge.org/external/6/674.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-02-06
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
#define MAX 7590
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
int ar[5][MAX];
int coin[] = {1, 5, 10, 25, 50};
int coin_change (int n) {
    for (int i = 0; i < 5; i++) {
        ar[i][0] = 1;
    }

    for (int i = 0; i <= n; i++) {
        ar[0][i] = 1;
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 1; j <= n; j++) {
            if (coin[i] > j) {
                ar[i][j] = ar[i - 1][j];

            } else {
                ar[i][j] = (ar[i][j - coin[i]]) + ar[i - 1][j];
            }
        }
    }

    return ar[4] [n];
}

int main () {
    __FastIO;
    int n;

    while (cin >> n) {
        if (n == 0) cout << 1 << "\n";
        else cout << coin_change (n) << "\n";
    }

    return 0;
}

