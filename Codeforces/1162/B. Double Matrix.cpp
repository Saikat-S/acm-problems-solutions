/***************************************************
 * Problem Name : B. Double Matrix.cpp
 * Problem Link : https://codeforces.com/contest/1162/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-08
 * Problem Type : Div 2 - B
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
#define MAX 50
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
    int n, m;
    cin >> n >> m;
    int ar[MAX][MAX], br[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> br[i][j];
        }
    }

    static int ans[MAX][MAX];
    static int ans1[MAX][MAX];
    ans[0][0] = min (ar[0][0], br[0][0]);
    ans1[0][0] = max (ar[0][0], br[0][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;

            int x1 = ar[i][j];
            int x2 = br[i][j];

            if (i == 0) {
                if (ans[i][j - 1] < min (x1, x2) && ans1[i][j - 1] < max (x1, x2) ) {
                    ans[i][j] = min (x1, x2);
                    ans1[i][j] = max (x1, x2);

                } else if (ans[i][j - 1] < max (x1, x2) && ans1[i][j - 1] < min (x1, x2) ) {
                    ans[i][j] = max (x1, x2);
                    ans1[i][j] = min (x1, x2);

                } else {
                    cout << "Impossible\n";
                    exit (0);
                }

            } else if (j == 0) {
                if (ans[i - 1][j] < min (x1, x2) && ans1[i - 1][j] < max (x1, x2) ) {
                    ans[i][j] = min (x1, x2);
                    ans1[i][j] = max (x1, x2);

                } else if (ans[i - 1][j] < max (x1, x2) && ans1[i - 1][j] < min (x1, x2) ) {
                    ans[i][j] = max (x1, x2);
                    ans1[i][j] = min (x1, x2);

                } else {
                    cout << "Impossible\n";
                    exit (0);
                }

            } else {
                if (ans[i][j - 1] < min (x1, x2) && ans[i - 1][j] < min (x1, x2)
                    && ans1[i][j - 1] < max (x1, x2) && ans1[i - 1][j] < max (x1, x2) ) {
                    ans[i][j] = min (x1, x2);
                    ans1[i][j] = max (x1, x2);

                } else if (ans[i][j - 1] < max (x1, x2) && ans[i - 1][j] < max (x1, x2)
                           && ans1[i][j - 1] < min (x1, x2) && ans1[i - 1][j] < min (x1, x2) ) {
                    ans[i][j] = max (x1, x2);
                    ans1[i][j] = min (x1, x2);

                } else {
                    cout << "Impossible\n";
                    exit (0);
                }
            }
        }
    }

    cout << "Possible\n";
    return 0;
}
