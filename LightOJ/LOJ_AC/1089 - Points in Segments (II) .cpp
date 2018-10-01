/***************************************************
 * Problem Name : 1089 - Points in Segments (II) .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1089
 * OJ           : LightOJ
 * Verdict      : AC
 * Date         : 2018-09-26
 * Problem Type : Data Structure (segment tree with lazy)
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
#define MAX 150005
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
int tree[MAX * 4], lazy[MAX * 4];
void build (int nod, int low, int high) {
    if (low > high) return ;

    if (low == high) {
        tree[nod] = 0;
        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    build (left, low, mid);
    build (right, mid + 1, high);
    tree[nod] = tree[left] + tree[right];
}
int query (int nod, int low, int high, int qlow, int qhigh) {
    if (low > high || low > qhigh || high < qlow) {
        return 0;
    }

    if (lazy[nod] != 0) {
        tree[nod] += (lazy[nod] * (high - low + 1) );

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low >= qlow && high <= qhigh) {
        return tree[nod];
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
        tree[nod] += (lazy[nod] * (high - low + 1) );

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
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
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] += val;
            lazy[right] += val;
        }

        return;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
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
        vector<pair<int, int> >vv;
        set<int>st;
        map<int, int>mp;

        for (int i = 0; i < n; i++) {
            int a, b;
            scanf ("%d %d", &a, &b);
            vv.pb (mk (a, b) );
            st.insert (a);
            st.insert (b);
        }

        vector<int>qry;

        while (q--) {
            int x;
            scanf ("%d", &x);
            qry.pb (x);
            st.insert (x);
        }

        int k = 0;
        set<int>::iterator it;

        for (it = st.begin(); it != st.end(); it++) {
            if (mp[*it] == 0) {
                mp[*it] = k++;
            }
        }

        build (1, 0, k - 1);

        for (int i = 0; i < n; i++) {
            update (1, 0, k - 1, mp[vv[i].first], mp[vv[i].second], 1);
        }

        printf ("Case %d:\n", t);

        for (int i = 0; i < (int) qry.size(); i++) {
            printf ("%d\n", query (1, 0, k - 1, mp[qry[i]], mp[qry[i]]) );
        }

        SET (tree, 0);
        SET (lazy, 0);
    }

    return 0;
}
