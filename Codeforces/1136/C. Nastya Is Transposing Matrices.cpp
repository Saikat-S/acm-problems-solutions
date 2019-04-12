/***************************************************
 * Problem Name : C. Nastya Is Transposing Matrices.cpp
 * Problem Link : https://codeforces.com/contest/1136/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-03-11
 * Problem Type : Div 2 - C
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

    vector<int>V1[MAX], V2[MAX];
    int k = 0;

    for (int ii = 0; ii < n; ii++) {
        int j = 0;
        int i = ii;

        while (true) {
            if (j > m || i < 0 ) {
                break;
            }

            V1[k].pb (ar[i][j]);
            i--;
            j++;
        }

        sort (all (V1[k]) );
        k++;
    }

    for (int jj = 1; jj < m; jj++) {
        int i = n - 1;
        int j = jj;

        while (true) {
            if (i > n || j > m || i < 0 || j < 0) {
                break;
            }

            V1[k].pb (ar[i][j]);
            i--;
            j++;
        }

        sort (all (V1[k]) );
        k++;
    }

    k = 0;

    for (int ii = 0; ii < n; ii++) {
        int i = ii;
        int j = 0;

        while (true) {
            if (i > n || j > m || i < 0 || j < 0) {
                break;
            }

            V2[k].pb (br[i][j]);
            i--;
            j++;
        }

        sort (all (V2[k]) );
        k++;
    }

    for (int jj = 1; jj < m; jj++) {
        int i = n - 1;
        int j = jj;

        while (true) {
            if (j > m || i < 0) {
                break;
            }

            V2[k].pb (br[i][j]);
            i--;
            j++;
        }

        sort (all (V2[k]) );
        k++;
    }

    bool flag = true;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (int) V1[i].size(); j++) {
            if (V1[i][j] != V2[i][j]) {
                flag = false;
            }
        }

        if (!flag) break;
    }

    if (!flag) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
