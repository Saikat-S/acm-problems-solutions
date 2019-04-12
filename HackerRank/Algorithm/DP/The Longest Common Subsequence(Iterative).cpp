/***************************************************
 * Problem Name : The Longest Common Subsequence(Iterative).cpp
 * Problem Link : https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
 * OJ           : HackerRank
 * Verdict      : AC
 * Date         : 2019-04-04
 * Problem Type : DP(iterative)
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
#define pll pair <int, int>
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
#define MAX 1005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long int;
typedef unsigned long long ull;

template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
int lcm (int a, int b) {
    return a * b / __gcd (a, b);
}
/************************************ Code Start Here ******************************************************/
vector<int>A, B;
int dp[MAX][MAX];
int lcsIterative (int n, int m) {
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

            } else {
                dp[i][j] = max (dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][m];
}

void path (int n, int m) {
    vector<int>ans;
    int i = n, j = m;
    int ln = lcsIterative (n, m);

    while (1) {
        if (dp[i][j] == ln && A[i] == B[j]) {
            ans.pb (A[i]);
            i--, j--;
            ln--;

        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                i--;

            } else {
                j--;
            }
        }

        if (ln == 0) break;
    }

    reverse (all (ans) );

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }

    nl;
}


int main () {
    //~ __FastIO;
    int n, m;
    cin >> n >> m;
    A = vector<int> (n + 1);
    B = vector<int> (m + 1);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    path (n, m);
    return 0;
}
