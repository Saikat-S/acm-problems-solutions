/***************************************************
 * Problem Name : 1134 - Be Efficient.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1134
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2019-07-09
 * Problem Type : DP(*)
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
int main () {
    __FastIO;
    int tc, n, m;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        int sum[MAX];
        sum[0] = 0;
        ll cnt = 0;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            if (x == 0) cnt++;

            sum[i] = (sum[i - 1] + x) % m;
        }

        int chk[MAX];
        SET (chk, 0);

        for (int i = 1; i <= n; i++) {
            int x = sum[i];

            if (sum[i] == 0) {
                cnt += (ll) (++chk[x]);

            } else if (x != 0) {
                cnt += (ll) (chk[x]++);

            } else {
                chk[x]++;
            }
        }

        cout << "Case " << t << ": " << cnt << "\n";
    }

    return 0;
}

