/***************************************************
 * Problem Name : 10600 ACM contest and Blackout.cpp
 * Problem Link : https://uva.onlinejudge.org/external/106/10600.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-09-14
 * Problem Type : Graph (MST)
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
#define MAX 105
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
struct edge {
    int u, v, w;
};
vector<edge>E;
vector<int>V;

int par[MAX];

bool cmp ( edge a, edge b ) {
    return a.w < b.w;
}

void makeSet (int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find (int r ) {
    if ( par[r] == r ) return r;

    return par[r] = find ( par[r] );
}

int MST (int n) {
    makeSet (n);
    sort (all (E), cmp);
    int sum = 0, cnt = 0;

    for (int i = 0; i < (int) E.size(); i++) {
        int u = find (E[i].u );
        int v = find (E[i].v );

        if ( u != v ) {
            par[u] = v;
            V.push_back (i);
            sum += E[i].w;
            cnt++;

            if (cnt == n - 1) break;
        }
    }

    return sum;
}

int MST_1 (int x, int n) {
    makeSet (n);
    int sum = 0, cnt = 0;

    for (int i = 0; i < (int) E.size(); i++) {
        if (i == x) continue;

        int u = find (E[i].u );
        int v = find (E[i].v );

        if ( u != v ) {
            par[u] = v;
            sum += E[i].w;
            cnt++;

            if (cnt == n - 1) break;
        }
    }

    return sum;
}
int secondMST (int n, int sum) {
    int mn = 30005;

    for (int i = 0; i < (int) V.size(); i++) {
        int ans = MST_1 (V[i], n);

        if (ans >= sum) mn = min (mn, ans);
    }

    return mn;
}
int main () {
    __FastIO;
    int tc, N, M;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> N >> M;

        for (int i = 1; i <= M; i++) {
            edge get ;
            cin >> get.u >> get.v >> get.w;
            E.pb (get);
        }

        int sum1 = MST (N);
        int sum2 = secondMST (N, sum1);
        cout << sum1 << " " << sum2 << "\n";
        E.clear(), V.clear();
    }

    return 0;
}
