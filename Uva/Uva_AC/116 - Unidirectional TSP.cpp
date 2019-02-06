/***************************************************
 * Problem Name : 116 - Unidirectional TSP.cpp
 * Problem Link : https://uva.onlinejudge.org/external/1/116.pdf
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
#define __FileRead freopen ("/home/saikat/Desktop/logN/input.txt", "r", stdin);
#define __FileWrite freopen ("/home/saikat/Desktop/logN/output.txt", "w", stdout);
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
#define MAX 105
#define INF 1000000009
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
int ar[MAX][MAX];
int dp[MAX][MAX];
int n, m;
vector<int>vec;
int fun (int i, int j) {
    if (i < 1) {
        i = n;
    }

    if (i > n) {
        i = 1;
    }

    if (j == m) return dp[i][j] = ar[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    int a = INF, b = INF, c = INF;
    a = ar[i][j] + fun (i - 1, j + 1);
    b = ar[i][j] + fun (i, j + 1);
    c = ar[i][j] +  fun (i + 1, j + 1);
    return dp[i][j] = Min3 (a, b, c);
}
void print (int i, int j) {
    if (j == m) {
        return ;
    }

    if (i == 1) {
        int a = dp[n][j + 1];
        int b = dp[i][j + 1];
        int c = dp[i + 1][j + 1];

        if (i + 1 > n) c = INF;

        if (a <= b && a <= c) {
            if (a == b) {
                vec.pb (i);
                print (i, j + 1);

            } else if (a == c) {
                vec.pb (i + 1);
                print (i + 1, j + 1);

            } else {
                vec.pb (n);
                print (n, j + 1);
            }

        } else if (c <= a && c <= b) {
            if (c == b) {
                vec.pb (i);
                print (i, j + 1);

            } else {
                vec.pb (i + 1);
                print (i + 1, j + 1);
            }

        } else {
            vec.pb (i);
            print (i, j + 1);
        }

    } else if (i == n) {
        int a = dp[i - 1][j + 1];
        int b = dp[i][j + 1];
        int c = dp[1][j + 1];

        if (i - 1 < 1) a = INF;

        if (b <= a && b <= c) {
            if (b == c) {
                vec.pb (1);
                print (1, j + 1);

            } else if (b == a) {
                vec.pb (i - 1);
                print (i - 1, j + 1);

            } else {
                vec.pb (i);
                print (i, j + 1);
            }

        } else if (a <= b && a <= c) {
            if (a == c) {
                vec.pb (1);
                print (1, j + 1);

            } else {
                vec.pb (i - 1);
                print (i - 1, j + 1);
            }

        } else {
            vec.pb (1);
            print (1, j + 1);
        }

    } else {
        int a = dp[i - 1][j + 1];
        int b = dp[i][j + 1];
        int c = dp[i + 1][j + 1];

        if (i - 1 < 1) a = INF;

        if (i + 1 > n) c = INF;

        if (c <= a && c <= b) {
            if (c == a) {
                vec.pb (i - 1);
                print (i - 1, j + 1);

            } else if (c == b) {
                vec.pb (i);
                print (i, j + 1);

            } else {
                vec.pb (i + 1);
                print (i + 1, j + 1);
            }

        } else if (b <= a && b <= c) {
            if (b == a) {
                vec.pb (i - 1);
                print (i - 1, j + 1);

            } else {
                vec.pb (i);
                print (i, j + 1);
            }

        } else {
            vec.pb (i - 1);
            print (i - 1, j + 1);
        }
    }
}
int main () {
    __FastIO;

    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> ar[i][j];
            }
        }

        int mn = INF;
        int id;

        for (int i = 1; i <= n; i++) {
            SET (dp, -1);
            int ans = fun (i, 1);

            if (mn > ans) {
                id = i;
                mn  = ans;
            }
        }

        SET (dp, -1);
        int an = fun (id, 1);
        vec.pb (id);
        print (id, 1);

        for (int i = 0; i < (int) vec.size(); i++) {
            if (i != 0) cout << " ";

            cout << vec[i];
        }

        nl;
        cout << an << "\n";
        vec.clear();
    }

    return 0;
}
