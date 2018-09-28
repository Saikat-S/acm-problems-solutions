/***************************************************
 * Problem Name : 1133 - Array Simulation .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1133
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-27
 * Problem Type : AdHoc
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
#define MAX 100005
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
int main () {
    //~ __FastIO;
    int tc, n, m;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &m);
        vector<int>v (n);

        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
        }

        while (m--) {
            getchar();
            char ch;
            int D;
            scanf ("%c", &ch);

            if (ch == 'S') {
                scanf ("%d", &D);

                for (int i = 0 ; i < n; i++) v[i] += D;

            } else if (ch == 'M') {
                scanf ("%d", &D);

                for (int i = 0 ; i < n; i++) v[i] *= D;

            } else if (ch == 'D') {
                scanf ("%d", &D);

                for (int i = 0 ; i < n; i++) v[i] /= D;

            } else if (ch == 'R') {
                reverse (all (v) );

            } else {
                int x, y;
                scanf ("%d %d", &x, &y);
                swap (v[x], v[y]);
            }
        }

        printf ("Case %d:\n", t);

        for (int i = 0; i < n; i++) {
            if (i != 0) printf (" ");

            printf ("%d", v[i]);
        }

        printf ("\n");
    }

    return 0;
}
