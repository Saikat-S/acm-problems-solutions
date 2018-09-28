/***************************************************
 * Problem Name : 1348 - Aladdin and the Return Journey .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1348
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2018-09-22
 * Problem Type : Data Structure (Segment Tree , LCA)
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
#define MAX 30005
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
vector<int>adj[MAX];
int ar[MAX], dis[MAX], ed[MAX], Time;
int level[MAX], par[MAX];
int table[MAX][17];
int hihi[MAX * 2];
int tree[MAX * 3];
void dfs (int u, int p) {
    dis[u] = Time;
    hihi[Time++] = ar[u];

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (v == p) continue;

        level[v] = level[u] + 1;
        par[v] = u;
        dfs (v, u);
    }

    ed[u] = Time;
    hihi[Time++] = ar[u] * -1;
}
void LCA (int n) {
    SET (table, -1);

    for (int i = 0; i < n; i++) {
        table[i][0] = par[i];
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            if (table[i][j - 1] != -1) {
                int x = table[i][j - 1];
                table[i][j] = table[x][j - 1];
            }
        }
    }
}
int LCA_Quary (int u, int v) {
    if (level[u] < level[v]) swap (u, v);

    int lim = log2 (level[u]);

    for (int i = lim; i >= 0; i--) {
        if (level[u] - (1 << i) >= level[v]) {
            u = table[u][i];
        }
    }

    if (u == v) return u;

    for (int i = lim; i >= 0; i--) {
        if (table[u][i] != -1 && table[u][i] != table[v][i]) {
            u = table[u][i];
            v = table[v][i];
        }
    }

    return par[u];
}

void build (int nod, int low, int high) {
    if (low == high) {
        tree[nod] = hihi[low];

    } else {
        int mid = (high + low) / 2;
        int left = nod * 2 ;
        int right = nod * 2 + 1;
        build (left, low, mid);
        build (right, mid + 1, high);
        tree[nod] = tree[left] + tree[right];
    }
}

int query (int nod, int low, int high, int l, int r) {
    if (low > r || high < l) {
        return 0;
    }

    if (low >= l && high <= r) {
        return tree[nod];
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;
    return query (left, low, mid, l, r) + query (right, mid + 1, high, l, r);
}

void update (int nod, int low, int high, int pos, int val) {
    if (low  == high) {
        tree[nod] = val;
        return ;
    }

    int mid = (high + low) / 2;
    int left = nod * 2;
    int right = nod * 2 + 1;

    if (pos <= mid) update (left, low, mid, pos, val);
    else update (right, mid + 1, high, pos, val);

    tree[nod] = tree[left] + tree[right];
}

int main () {
    int tc, n;
    scanf ("%d", &tc);

    for (int t = 1; t <= tc; t++) {
        scanf ("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf ("%d", &ar[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf ("%d %d", &u, &v);
            adj[u].pb (v);
            adj[v].pb (u);
        }

        level[0] = 0;
        par[0] = -1;
        Time = 1;
        dfs (0, -1);
        build (1, 1, n * 2);
        LCA (n);
        int Q;
        scanf ("%d", &Q);
        printf ("Case %d:\n", t);

        for (int q = 1; q <= Q; q++) {
            int c, i, j;
            scanf ("%d %d %d", &c, &i, &j);

            if (!c) {
                int r = LCA_Quary (i, j);
                int sum1 = query (1, 1, n * 2, dis[r], dis[i]);
                int sum2 = query (1, 1, n * 2, dis[r], dis[j]);
                int sum = (sum1 + sum2) - ar[r];
                printf ("%d\n", sum);

            } else {
                ar[i] = j;
                update (1, 1, n * 2, dis[i], j);
                update (1, 1, n * 2, ed[i], j * -1);
            }
        }

        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
    }

    return 0;
}
