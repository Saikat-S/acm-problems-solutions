/***************************************************
 * Problem Name : 1112 - Curious Robin Hood(using_BIT).cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1112
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-10-02
 * Problem Type : Data Stucture (BIT)
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
int tree[MAX];
int getNext (int id) {
    return id + (id & -id);
}
int getPar (int id) {
    return id - (id & -id);
}
void update (int id, int n, ll val) {
    while (id <= n) {
        tree[id] += val;
        id = getNext (id);
    }
}
int query (int id) {
    int sum = 0;
    id++;

    while (id > 0 ) {
        sum += tree[id];
        id = getPar (id);
    }

    return sum;
}
int main () {
    //~ __FastIO;
    int tc, n, q;
    int ar[MAX];
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &q);

        for (int i = 0; i < n; i++) {
            scanf ("%d", &ar[i]);
        }

        for (int i = 1; i <= n; i++) {
            update (i, n, ar[i - 1]);
        }

        printf ("Case %d:\n", t);

        while (q--) {
            int c, x;
            int v;
            scanf ("%d", &c);

            if (c == 1) {
                scanf ("%d", &x);
                printf ("%d\n", ar[x]);
                update (x + 1, n, ar[x] * -1);
                ar[x] = 0;

            } else if (c == 2) {
                scanf ("%d %d", &x, &v);
                update (x + 1, n, v);
                ar[x] += v;

            } else {
                scanf ("%d %d", &x, &v);
                printf ("%d\n", (query (v) - query (x) ) + ar[x]);
            }
        }

        SET (tree, 0);
    }

    return 0;
}
