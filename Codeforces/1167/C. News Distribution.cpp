/***************************************************
 * Problem Name : C. News Distribution.cpp
 * Problem Link : https://codeforces.com/contest/1167/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-05-30
 * Problem Type : Edu R - C
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define MAX 500005
#define INF 1000000000
#define MOD 1000000007
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
int par[MAX], sz[MAX];
void init (int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find (int r) {
    if (par[r] == r) return r;
    else return  par[r] = find (par[r]);
}

void makeSet (int u, int v) {
    int uu = find (u);
    int vv = find (v);

    if (uu != vv) {
        if (sz[uu] < sz[vv]) swap (uu, vv);

        par[vv] = uu;
        sz[uu] += sz[vv];
    }
}


int main () {
    __FastIO;
    int n, m;
    cin >> n >> m;
    init (n);

    for (int i = 0; i < m; i++) {
        int x, u;
        cin >> x;

        if (x != 0) {
            cin >> u;
            x--;

            for (int j = 0; j < x; j++) {
                int v;
                cin >> v;
                makeSet (u, v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << sz[find (i)] << ' ';
    }

    nl;
    return 0;
}
