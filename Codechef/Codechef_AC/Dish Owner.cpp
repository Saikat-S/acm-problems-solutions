/***************************************************
 * Problem Name : Dish Owner.cpp
 * Problem Link : https://www.codechef.com/problems/DISHOWN
 * OJ           : Codechef
 * Verdict      : AC
 * Date         : 2018-05-31
 * Problem Type : Data Stucture (DSU)
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
int par[MAX], s[MAX];
int fnd (int u) {
    if (u == par[u]) return u;

    return par[u] = fnd (par[u]);
}
int main () {
    //~ __FastIO;
    int TC;
    scanf ("%d", &TC);

    while (TC--) {
        int n;
        scanf ("%d", &n);

        for (int i = 1; i <= n; i++) par[i] = i;

        for (int i = 1; i <= n; i++) {
            scanf ("%d", &s[i]);
        }

        int q;
        scanf ("%d", &q);

        while (q--) {
            int ch, a, b;
            scanf ("%d", &ch);

            if (ch == 0) {
                scanf ("%d %d", &a, &b);
                int pa = fnd (a);
                int pb = fnd (b);

                if (pa == pb) printf ("Invalid query!\n");
                else {
                    if (s[pa] > s[pb]) par[pb] = pa;
                    else if (s[pa] < s[pb]) par[pa] = pb;
                }

            } else {
                scanf ("%d", &a);
                int pa = fnd (a);
                printf ("%d\n", pa);
            }
        }
    }

    return 0;
}
