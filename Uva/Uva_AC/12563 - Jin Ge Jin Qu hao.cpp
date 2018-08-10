/***************************************************
 * Problem Name : 12563 - Jin Ge Jin Qu hao.cpp
 * Problem Link : https://uva.onlinejudge.org/external/125/12563.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-07-17
 * Problem Type : DP (KnapSack)
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
#define pb push_back
#define MAX 55
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
int N;
int cap;
int ar[MAX];
int dp[MAX][10000];
int dir[MAX][10000];
int knapSack (int i, int w) {
    if (i == N) return 0;

    if (dp[i][w] != -1) return dp[i][w];

    int pro1 = 0, pro2 = 0;

    if (w - ar[i] >= 0) {
        pro1 = 1 + knapSack (i + 1, w - ar[i]);
    }

    pro2 = knapSack (i + 1, w);
    return  dp[i][w] = max (pro1, pro2);
}
int print (int i, int w) {
    if (i == N) return 0;

    if (dir[i][w] != -1) return dir[i][w] ;

    int pro1 = -1, pro2 = -1;
    int pro = knapSack (i, w);

    if (w + ar[i] >= 0) {
        pro1 = 1 + knapSack (i + 1, w - ar[i]);
    }

    pro2 = knapSack (i + 1, w);
    int sum1 = 0, sum2 = 0;

    if (pro == pro1) sum1 = ar[i] + print (i + 1, w - ar[i]);

    if (pro == pro2) sum2 = print (i + 1, w);

    return dir[i][w] = max (sum1, sum2);
}
int main () {
    __FastIO;
    int tc;
    int T;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> N >> T;
        cap = T - 1;

        for (int i = 0; i < N; i++) {
            cin >> ar[i];
        }

        SET (dp, -1);
        SET (dir, -1);
        sort (ar, ar + N);
        int cnt = knapSack (0, cap) + 1;
        int ans = print (0, cap) + 678;
        cout << "Case " << t << ": " << cnt << " " << ans << "\n";
    }

    return 0;
}
