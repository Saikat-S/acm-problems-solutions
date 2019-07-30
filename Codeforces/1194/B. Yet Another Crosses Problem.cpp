/***************************************************
 * Problem Name : B. Yet Another Crosses Problem.cpp
 * Problem Link : https://codeforces.com/contest/1194/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-14
 * Problem Type : Edu R - B
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
#define MAX 50005
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
    int q, n, m;
    cin >> q;

    while (q--) {
        cin >> n >> m;
        //~ string str[MAX]; // reason for time limit
        vector<string>str (n);

        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }

        //~ int *a = (int *) calloc (n, sizeof (int) );
        //~ int *b = (int *) calloc (m, sizeof (int) );
        //~ for (int i = 0; i < n; i++) {
        //~ for (int j = 0; j < m; j++) {
        //~ if (str[i][j] == '*') {
        //~ a[i]++, b[j]++;
        //~ }
        //~ }
        //~ }
        //~ int ans =  n + m;
        //~ for (int i = 0; i < n; i++) {
        //~ for (int j = 0; j < m; j++) {
        //~ int tmp = (n+m) - (a[i] + b[j]);
        //~ if (str[i][j] == '.') tmp--;
        //~ ans = min (ans, tmp);
        //~ }
        //~ }
        //~ cout << ans << "\n";
        int mx_row = 0, pos_row;
        vector<int>v1, v2;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < m; j++) {
                if (str[i][j] == '*') cnt++;
            }

            if (cnt >= mx_row) {
                mx_row = cnt;
                pos_row = i;
            }
        }

        // for check
        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < m; j++) {
                if (str[i][j] == '*') cnt++;
            }

            if (cnt == mx_row) {
                v1.pb (i);
            }
        }

        int mx_col = 0, pos_col;

        for (int j = 0; j < m; j++) {
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (str[i][j] == '*') cnt++;
            }

            if (cnt >= mx_col) {
                mx_col = cnt;
                pos_col = j;
            }
        }

        // for check
        for (int j = 0; j < m; j++) {
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (str[i][j] == '*') cnt++;
            }

            if (cnt == mx_col) {
                v2.pb (j);
            }
        }

        int ans =  (n + m) - (mx_row + mx_col);

        if (str[pos_row][pos_col] == '.') ans--;

        for (int i = 0; i < (int) v1.size(); i++) {
            int ii = v1[i];

            for (int j = 0; j < (int) v2.size(); j++) {
                int jj = v2[j];
                int tmp =  (n + m) - (mx_row + mx_col);

                if (str[ii][jj] == '.') tmp--;

                ans = min (ans, tmp);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
