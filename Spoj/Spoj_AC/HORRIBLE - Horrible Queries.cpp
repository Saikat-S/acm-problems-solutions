/***************************************************
 * Problem Name : HORRIBLE - Horrible Queries.cpp
 * Problem Link : https://www.spoj.com/problems/HORRIBLE/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-09-23
 * Problem Type : Data Structure (Lagy Propagate)
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
ll arr[MAX], tree[MAX * 3], lazy[MAX * 3];
void build (ll node, ll a, ll b) {
    if (a > b) return;

    if (a == b) {
        tree[node] = arr[a];
        return;
    }

    build (node * 2, a, (a + b) / 2);
    build (node * 2 + 1, (a + b) / 2 + 1, b);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query (ll node, ll a, ll b, ll i, ll j) {
    if (a > b || a > j || b < i) return 0;

    if (lazy[node] != 0 ) {	
        tree[node] += lazy[node] * (ll) (b - a + 1);

        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (a >= i && b <= j) return tree[node];

    ll q1 = query (node * 2, a, (a + b) / 2, i, j);
    ll q2 = query (node * 2 + 1, (a + b) / 2 + 1, b, i, j);
    return q1 + q2;
}

void update (ll node, ll a, ll b, ll i, ll j,
             ll inc) {
    if (a > b) return;

    if (lazy[node] != 0) {
        tree[node] += lazy[node] * (ll) (b - a + 1);

        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }	

    if (a > b || a > j || b < i) return;

    if (a >= i && b <= j) {
        tree[node] += inc * (b - a + 1);

        if (a != b) {
            lazy[node * 2] += inc;
            lazy[node * 2 + 1] += inc;
        }

        return;
    }

    update (node * 2, a, (a + b) / 2, i, j, inc);
    update (node * 2 + 1, (a + b) / 2 + 1, b, i, j, inc);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main () {
    __FastIO;
    int tc, n, q;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> q;
        build (1, 0, n - 1);
        SET (lazy, 0);

        while (q--) {
            int c, u, v, val;
            cin >> c;

            if (c == 0) {
                cin >> u >> v >> val;
                update (1, 0, n - 1, u - 1, v - 1, val);

            } else {
                cin >> u >> v;
                cout << query (1, 0, n - 1, u - 1, v - 1) << "\n";
            }
        }
    }

    return 0;
}
