/***************************************************
 * Problem Name : Sasha, Misha & Their String Fight.cpp
 * Problem Link : https://toph.co/p/sasha-misha-their-string-fight
 * OJ           : Toph
 * Verdict      : AC
 * Date         : 2019-04-14
 * Problem Type : DP(LCS)
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
int lcs (int i, int j) {
    if (i == (int) A.size() || j == (int) B.size() ) {
        return 0;
    }

    int &ans = dp[i][j];

    if (ans != -1) return ans;

    ans = 0;

    if (A[i] == B[j]) {
        ans = 1 + lcs (i + 1, j + 1);

    } else {
        int a = lcs (i + 1, j);
        int b = lcs (i, j + 1);
        ans = max (a, b);
    }

    return ans;
}
void path (int i, int j) {
    if (i == (int) A.size() || j == (int) B.size() ) {
        nl;
        return;
    }

    if (A[i] == B[j]) {
        cout << A[i];
        path (i + 1, j + 1);

    } else {
        if (dp[i + 1][j] >= dp[i][j + 1]) {
            path (i + 1, j);

        } else {
            path (i, j + 1);
        }
    }
}


int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> A >> B;
        SET (dp, -1);
        lcs (0, 0);
        path (0, 0);
    }

    return 0;
}
