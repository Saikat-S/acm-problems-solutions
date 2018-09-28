/***************************************************
 * Problem Name : 1164 - Horrible Queries.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1164
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
ll ar[MAX], tree[MAX * 3], lazy[MAX * 3];
void build (ll nod, ll low, ll high) {
    if (low > high) return ;

    if (low == high) {
        tree[nod] = ar[low];
        return ;
    }

    ll mid = (high + low) / 2;
    ll left = nod * 2;
    ll right = nod * 2 + 1;
    build (left, low, mid);
    build (right, mid + 1, high);
    tree[nod] = tree[left] + tree[right];
}
ll query (ll nod, ll low, ll high, ll qlow, ll qhigh) {
    if (low > high || low > qhigh || high < qlow) {
        return 0;
    }

    if (lazy[nod] != 0) {
        tree[nod] += (lazy[nod] * (high - low + 1) );

        if (low != high) {
            ll left = nod * 2;
            ll right = nod * 2 + 1;
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low >= qlow && high <= qhigh) {
        return tree[nod];
    }

    ll mid = (high + low) / 2;
    ll left = nod * 2;
    ll right = nod * 2 + 1;
    ll q1 = query (left, low, mid, qlow, qhigh);
    ll q2 = query (right, mid + 1, high, qlow, qhigh);
    return q1 + q2;
}
void update (ll nod, ll low, ll high, ll qlow, ll qhigh, ll val) {
    if (low > high) return ;

    if (lazy[nod] != 0) {
        tree[nod] += (lazy[nod] * (high - low + 1) );

        if (low != high) {
            ll left = nod * 2;
            ll right = nod * 2 + 1;
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low > qhigh || high < qlow) {
        return;
    }

    if (low >= qlow && high <= qhigh) {
        tree[nod] += (val * (high - low + 1) );

        if (low != high) {
            ll left = nod * 2;
            ll right = nod * 2 + 1;
            lazy[left] += val;
            lazy[right] += val;
        }

        return;
    }

    ll mid = (high + low) / 2;
    ll left = nod * 2;
    ll right = nod * 2 + 1;
    update (left, low, mid, qlow, qhigh, val);
    update (right, mid + 1, high, qlow, qhigh, val);
    tree[nod] = tree[left] + tree[right];
}
int main () {
    //~ __FastIO;
    int tc, n, q;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &q);
        SET (ar, 0);
        SET (lazy, 0);
        build (1, 0, n - 1);
        printf ("Case %d:\n", t);

        while (q--) {
            ll c, x, y, val;
            scanf ("%lld", &c);

            if (!c) {
                scanf ("%lld %lld %lld", &x, &y, &val);
                update (1, 0, n - 1, x, y, val);

            } else {
                scanf ("%lld %lld", &x, &y);
                printf ("%lld\n", query (1, 0, n - 1, x, y) );
            }
        }
    }

    return 0;
}
