/***************************************************
* Problem Name : 1080 - Binary Simulation .cpp
* Problem Link : http://lightoj.com/volume_showproblem.php?problem=1080
* OJ           : LOJ
* Verdict      : AC
* Date         : 2018-09-27
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
int ar[MAX], tree[MAX * 3], lazy[MAX * 3], ans;
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
void query (int nod, int low, int high, int qlow, int qhigh) {
    if (low > high || low > qhigh || high < qlow) {
        return;
    }

    if (lazy[nod] != 0) {
        tree[nod] += lazy[nod];

        if (low != high) {
            int left = nod * 2;
            int right = nod * 2 + 1;
            lazy[left] += lazy[nod];
            lazy[right] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if (low >= qlow && high <= qhigh) {
        if (ar[low] == 1) {
            if (tree[nod] % 2 == 0) {
                ans = 1;

            } else {
                ans = 0;
            }

        } else {
            if (tree[nod] % 2 == 0) {
                ans = 0;

            } else {
                ans = 1;
            }
        }

        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    query (left, low, mid, qlow, qhigh);
    query (right, mid + 1, high, qlow, qhigh);
    return ;
}
void update (int nod, int low, int high, int qlow, int qhigh, int val) {
    if (low > high) return ;

    if (lazy[nod] != 0) {
        tree[nod] += lazy[nod];

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
        tree[nod] += val;

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
    int tc, n;
    string str;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        getchar();
        char str[MAX];
        fgets (str, MAX, stdin);
        n = strlen (str);

        for (int i = 0; i < n; i++) {
            ar[i] = str[i] - '0';
        }

        SET (lazy, 0);
        build (1, 0, n - 1);
        int q;
        scanf ("%d", &q);
        printf ("Case %d:\n", t);

        while (q--) {
            char ch;
            getchar();
            scanf ("%c", &ch);

            if (ch == 'I') {
                int x, y;
                scanf ("%d %d", &x, &y);
                update (1, 0, n - 1, x - 1, y - 1, 1);

            } else {
                int x;
                scanf ("%d", &x);
                query (1, 0, n - 1, x - 1, x - 1);
                printf ("%d\n", ans);
            }
        }
    }

    return 0;
}
