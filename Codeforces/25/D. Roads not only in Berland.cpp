/***************************************************
 * Problem Name : D. Roads not only in Berland.cpp
 * Problem Link : http://codeforces.com/contest/25/problem/D
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-05-31
 * Problem Type : Data Structure (DSU)
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
#define pb push_back
#define MAX 2005
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
/************************************ Code Start Here ******************************************************/
int par[MAX];
int mk[MAX];
vector<pii> dis;
int fnd (int u) {
    if (u == par[u]) return u;

    return par[u] = fnd (par[u]);
}
int main () {
    //~ __FastIO;
    int n;
    scanf ("%d", &n);

    for (int i = 1; i <= n; i++) par[i] = i;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf ("%d %d", &a, &b);
        int pa = fnd (a);
        int pb = fnd (b);

        if (pa != pb) {
            par[pb] = pa;

        } else {
            dis.pb (pii (a, b) );
            mk[pa] = 1;
        }
    }

    vector<int>v;
    int chk[MAX];
    SET (chk, 0);

    for (int i = 1; i <= n; i++) {
        int p = fnd (i);

        if (chk[p] == 0) {
            v.pb (p);
            chk[p] = 1;
        }
    }

    int ans = (int) dis.size();
    printf ("%d\n", ans);

    for (int i = 0; i < ans; i++) {
        int aa = dis[i].first;
        int bb = dis[i].second;
        int p = fnd (aa);

        for (int j = 0; j < (int) v.size(); j++) {
            int x = fnd (v[j]);

            if (p != x) {
                printf ("%d %d %d %d\n", aa, bb, aa, x);
                par[x] = p;
                break;
            }
        }
    }

    return 0;
}
