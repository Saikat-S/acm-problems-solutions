/***************************************************
 * Problem Name : 10405 - Longest Common Subsequence(Iterative).cpp
 * Problem Link : https://uva.onlinejudge.org/external/104/10405.pdf
 * OJ           : Uva
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
#define MAX 1005
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
string A, B;
int dp[MAX][MAX];
int lcsIterative (int sizeA, int sizeB) {
    string AA, BB;
    AA.resize (sizeA + 1);
    BB.resize (sizeB + 1);

    for (int i = 0; i < sizeA; i++) {
        AA[i + 1] = A[i];
    }

    for (int i = 0; i < sizeB; i++) {
        BB[i + 1] = B[i];
    }

    sizeA = (int) AA.size();
    sizeB = (int) BB.size();

    for (int i = 0; i < sizeA; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i < sizeB; i++) {
        dp[i][0] = 0;
    }

    for (int j = 1; j < sizeB; j++) {
        for (int i = 1; i < sizeA; i++) {
            if (AA[i] == BB[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

            } else {
                dp[i][j] = max (dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[sizeA - 1][sizeB - 1];
}

int main () {
    __FastIO;
    while (getline (cin, A) ) {
        getline (cin, B);
        int ans = lcsIterative ( (int) A.size(), (int) B.size() );
        cout << ans << "\n";
    }

    return 0;
}
