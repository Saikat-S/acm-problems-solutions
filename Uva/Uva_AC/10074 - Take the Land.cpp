/***************************************************
 * Problem Name : 10074 - Take the Land.cpp
 * Problem Link : https://uva.onlinejudge.org/external/100/10074.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2019-07-09
 * Problem Type : DP
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
#define MAX 105
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
int tree[MAX * 4][MAX * 4];
int vec[MAX][MAX];
int n, m, mx;
void build (int indx, int nod, int low, int high) {
    if (low == high) {
        tree[indx][nod] = low;
        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    build (indx, left, low, mid);
    build (indx, right, mid + 1, high);

    if (vec[indx][tree[indx][left]] <= vec[indx][tree[indx][right]]) {
        tree[indx][nod] = tree[indx][left];

    } else {
        tree[indx][nod] = tree[indx][right];
    }
}
int query (int indx, int nod, int low, int high, int qlow, int qhigh) {
    if (qlow > high || qhigh < low) {
        return 0;
    }

    if (qlow <= low && qhigh >= high) {
        return tree[indx][nod];
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    int a = query (indx, left, low, mid, qlow, qhigh);
    int b = query (indx, right, mid + 1, high, qlow, qhigh);

    if (vec[indx][a] <= vec[indx][b]) {
        return a;

    } else {
        return b;
    }
}
void solve (int indx, int l, int r) {
    if (l > r) return ;

    int idx = query (indx, 1, 1, m, l, r);
    int xx = vec[indx][idx] * (r - l + 1);
    mx = max (mx, xx);
    solve (indx, l, idx - 1);
    solve (indx, idx + 1, r);
}
int main () {
    __FastIO;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        SET (tree, 0);
        SET (vec, 0);
        int ar[MAX][MAX];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> ar[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1) {
                    if (ar[i][j] == 0) {
                        vec[i][j] = 1;

                    } else {
                        vec[i][j] = 0;
                    }

                } else {
                    if (ar[i][j] == 0) {
                        vec[i][j]  = vec[i - 1][j] + 1;

                    } else {
                        vec[i][j]  = 0;
                    }
                }
            }
        }

        for (int i = 0; i < MAX; i++) {
            vec[i][0] = 1000000;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            build (i, 1, 1, m);
        }

        for (int i = 1; i <= n; i++) {
            mx = 0;
            solve (i, 1, m);
            ans = max (ans, mx);
        }

        cout << ans << "\n";
    }

    return 0;
}
