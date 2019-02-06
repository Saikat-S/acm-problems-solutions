/***************************************************
 * Problem Name : 531 - Compromise.cpp
 * Problem Link : https://uva.onlinejudge.org/external/5/531.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-02-06
 * Problem Type : dp(lcs)
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
#define MAX 1005
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
vector<string>A, B, ans;
int dp[MAX][MAX];
int n, m;
int LCS (int i, int j) {
    if (i == n || j == m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    if (A[i] == B[j]) ans = 1 + LCS (i + 1, j + 1);
    else {
        int val1 = LCS (i + 1, j);
        int val2 = LCS (i, j + 1);
        ans = max (val1, val2);
    }

    return dp[i][j] = ans;
}
void printALCS (int i, int j) {
    if (i == n || j == m) {
        for (int k = 0; k < (int) ans.size(); k++) {
            if (k != 0) cout << " ";

            cout << ans[k];
        }

        nl;
        return;
    }

    if (A[i] == B[j]) {
        ans.pb (A[i]);
        printALCS (i + 1, j + 1);
        ans.erase (ans.end() - 1);

    } else {
        if (dp[i + 1][j] >= dp[i][j + 1]) printALCS (i + 1, j);
        else {
            printALCS (i, j + 1);
        }
    }
}
int main () {
    __FastIO;
    string str;

    while (cin >> str) {
        A.pb (str);

        while (cin >> str) {
            if (str == "#") break;

            A.pb (str);
        }

        while (cin >> str) {
            if (str == "#") break;

            B.pb (str);
        }

        n = (int) A.size();
        m = (int) B.size();
        SET (dp, -1);
        LCS (0, 0);
        printALCS (0, 0);
        A.clear(), B.clear(), ans.clear();
    }

    return 0;
}
