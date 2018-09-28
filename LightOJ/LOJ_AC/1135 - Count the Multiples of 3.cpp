/***************************************************
 * Problem Name : 1135 - Count the Multiples of 3.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1135
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-24
 * Problem Type : Data Structure (Segment tree with lazy)
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
int ar[MAX], lazy[MAX * 3];
int zero[MAX * 3], one[MAX * 3], two[MAX * 3];
void build (int nod, int low, int high) {
    if (low > high) return ;

    if (low == high) {
        zero[nod] = 1;
        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    build (left, low, mid);
    build (right, mid + 1, high);
    zero[nod] = zero[left] + zero[right];
    one[nod] = one[left] + one[right];
    two[nod] = two[left] + two[right];
}
int query (int nod, int low, int high, int qlow, int qhigh) {
    if (low > high || low > qhigh || high < qlow) {
        return 0;
    }

    if (lazy[nod] != 0) {
        if (lazy[nod] == 1) {
            int zz = two[nod];
            two[nod] = zero[nod];
            zero[nod] = one[nod];
            one[nod] = zz;

        } else {
            int zz  = two[nod];
            two[nod] = one[nod];
            one[nod] = zero[nod];
            zero[nod] = zz;
        }

        if (low != high) {
            lazy[nod * 2] += lazy[nod];
            lazy[nod * 2] %= 3;
            lazy[nod * 2 + 1] += lazy[nod];
            lazy[nod * 2 + 1] %= 3;
        }

        lazy[nod] = 0;
    }

    if (low >= qlow && high <= qhigh) {
        return zero[nod];
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    int q1 = query (left, low, mid, qlow, qhigh);
    int q2 = query (right, mid + 1, high, qlow, qhigh);
    return q1 + q2;
}
void update (int nod, int low, int high, int qlow, int qhigh, int val) {
    if (low > high) return ;

    if (lazy[nod] != 0) {
        if (lazy[nod] == 1) {
            int zz = two[nod];
            two[nod] = zero[nod];
            zero[nod] = one[nod];
            one[nod] = zz;

        } else {
            int zz  = two[nod];
            two[nod] = one[nod];
            one[nod] = zero[nod];
            zero[nod] = zz;
        }

        if (low != high) {
            lazy[nod * 2] += lazy[nod];
            lazy[nod * 2] %= 3;
            lazy[nod * 2 + 1] += lazy[nod];
            lazy[nod * 2 + 1] %= 3;
        }

        lazy[nod] = 0;
    }

    if (low > qhigh || high < qlow) return ;

    if (low >= qlow && high <= qhigh) {
        int zz = two[nod];
        two[nod] = zero[nod];
        zero[nod] = one[nod];
        one[nod] = zz;

        if (low != high) {
            lazy[nod * 2] += val;
            lazy[nod * 2] %= 3;
            lazy[nod * 2 + 1] += val;
            lazy[nod * 2 + 1] %= 3;
        }

        return;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    update (left, low, mid, qlow, qhigh, val);
    update (right, mid + 1, high, qlow, qhigh, val);
    zero[nod] = zero[left] + zero[right];
    one[nod] = one[left] + one[right];
    two[nod] = two[left] + two[right];
}
int main () {
    //~ __FastIO;
    int tc, n, q;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &q);
        SET (ar, 0);
        SET (zero, 0);
        SET (one, 0);
        SET (two, 0);
        SET (lazy, 0);
        build (1, 0, n - 1);
        printf ("Case %d:\n", t);

        while (q--) {
            int c, x, y;
            scanf ("%d %d %d", &c, &x, &y);

            if (!c) {
                update (1, 0, n - 1, x, y, 1);

            } else {
                printf ("%d\n", query (1, 0, n - 1, x, y) );
            }
        }
    }

    return 0;
}
