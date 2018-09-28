/***************************************************
 * Problem Name : 1082 - Array Queries (use segment tree).cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1082
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-17
 * Problem Type : Data Structure (Segment Tree)
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
int tree[MAX * 4], ar[MAX];
void build (int nod, int low, int high) {
    if (low == high) {
        tree[nod] = ar[low];

    } else {
        int mid = (low + high) / 2;
        build (nod * 2, low, mid);
        build (nod * 2 + 1, mid + 1, high);
        tree[nod] = min (tree[nod * 2],  tree[nod * 2 + 1]);
    }
}
int query (int nod, int low, int high, int left, int right) {
    if (left > right) {
        return 100005;
    }

    if (left == low && right == high) {
        return tree[nod];
    }

    int mid = (low + high) / 2;
    return min (query (nod * 2, low, mid, left, min (right, mid) ),
                query (nod * 2 + 1,
                       mid + 1,
                       high, max (left, mid + 1), right ) );
}
int main () {
    //~ __FastIO;
    int tc, N, Q;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &N, &Q);

        for (int i = 0; i < N; i++) {
            scanf ("%d", &ar[i]);
        }

        SET (tree, 0);
        build (1, 0, N - 1);
        printf ("Case %d:\n", t);

        for (int q = 1; q <= Q; q++) {
            int l, r;
            scanf ("%d %d", &l, &r);
            printf ("%d\n", query (1, 0, N - 1, --l, --r) );
        }
    }

    return 0;
}
