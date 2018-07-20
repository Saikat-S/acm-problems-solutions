/***************************************************
 * Problem Name : NITTROAD - Roads of NITT.cpp
 * Problem Link : http://www.spoj.com/problems/NITTROAD/en/
 * OJ           : Spoj
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
#define MAX 20005
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
struct st {
    int idx, val;
    char ch;
};
int size[MAX], par[MAX], ans;
void init (int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        size[i] = 1;
    }
}
int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}
void makeSet (int a, int b) {
    a = find (a);
    b = find (b);

    if (a != b) {
        if (size[a] < size[b]) {
            swap (a, b);
        }

        ans = ans - (size[a] * size[b]);
        par[b] = a;
        size[a] += size[b];
    }
}
int main () {
    __FastIO;
    int tc;
    cin >> tc;

    while (tc--) {
        int n, q;
        cin >> n;
        init (n);
        vector<pii>edge[MAX];

        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edge[i].pb (pii (u, v) );
        }

        cin >> q;
        st Q[MAX];
        map<int, int>mp;

        for (int i = 1; i <= q; i++) {
            char ch;
            int x;
            cin >> ch;

            if (ch == 'R') {
                cin >> x;
                Q[i].idx = x;
                Q[i].ch = ch;
                mp[x] = 1;

            } else {
                Q[i].ch = ch;
            }
        }

        int nn = n - 1;
        ans = (nn * (nn + 1) ) / 2;

        for (int i = 1; i <= n - 1; i++) {
            if (mp[i] == 0) {
                int a = edge[i][0].first;
                int b = edge[i][0].second;
                makeSet (a, b);
            }
        }

        vector<int>v;

        for (int i = q; i >= 1; i--) {
            char ch = Q[i].ch;

            if (ch == 'R') {
                int x = Q[i].idx;
                int a = edge[x][0].first;
                int b = edge[x][0].second;
                makeSet (a, b);

            } else {
                v.pb (ans);
            }
        }

        for (int i = (int) v.size() - 1; i >= 0; i--) {
            cout << v[i] << "\n";
        }
    }

    return 0;
}
