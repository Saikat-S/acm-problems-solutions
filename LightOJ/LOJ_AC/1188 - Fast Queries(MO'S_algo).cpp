/***************************************************
 * Problem Name : 1188 - Fast Queries.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1188
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-25
 * Problem Type : Data Structure (MO'S ALgo)
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
struct query {
    int id, l, r;
} Q[MAX];

int ar[MAX], Count[MAX];
int n, q, blockSz;
int l, r;
int sum, A[MAX];

bool cmp (query a, query b) {
    int block_a = a.l / blockSz;
    int block_b = b.l / blockSz;

    if (block_a == block_b) return a.r < b.r;

    return block_a < block_b;
}
void add (int x) {
    if (Count[ar[x]] == 0) sum++;

    Count[ar[x]]++;
}
void remove (int x) {
    Count[ar[x]]--;

    if (Count[ar[x]] == 0) sum--;
}
void MOS() {
    sort (Q, Q + q, cmp);

    for (int i = 0; i < q; i++) {
        while (l > Q[i].l) {
            add (--l);
        }

        while (r < Q[i].r) {
            add (++r);
        }

        while (l < Q[i].l) {
            remove (l++);
        }

        while (r > Q[i].r) {
            remove (r--);
        }

        int id = Q[i].id;
        A[id] = sum;
    }
}
int main () {
    //~ __FastIO;
    int tc;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &q);
        SET (Count, 0);
        blockSz = sqrt (n);

        for (int i = 0; i < n; i++) {
            scanf ("%d", &ar[i]);
        }

        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &Q[i].l, &Q[i].r);
            Q[i].l--, Q[i].r--;
            Q[i].id = i;
        }

        l = 0, r = -1, sum = 0;
        MOS();
        printf ("Case %d:\n", t);

        for (int i = 0; i < q; i++) {
            cout << A[i] << "\n";
        }
    }

    return 0;
}
