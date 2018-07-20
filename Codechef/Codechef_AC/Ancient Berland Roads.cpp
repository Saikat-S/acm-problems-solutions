/***************************************************
 * Problem Name : Ancient Berland Roads.cpp
 * Problem Link : https://www.codechef.com/problems/ABROADS
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
#define MAX 500015
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
    int idx, u, val;
    char ch;
} Q[MAX];;

vector<int>V[MAX];
vector<pii>edge[MAX];
multiset<ll>ans;
multiset<ll>::iterator it;
int par[MAX];
int size[MAX];
ll S[MAX];

ll getSize() {
    it = ans.end();
    it--;
    return *it;
}

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
    int aa = find (a);
    int bb = find (b);

    if (aa != bb) {
        if (size[aa] < size[bb]) {
            swap (aa, bb);
        }

        it = ans.find (S[aa]);

        if (it != ans.end() ) {
            ans.erase (it);
        }

        it = ans.find (S[bb]);

        if (it != ans.end() ) {
            ans.erase (it);
        }

        par[bb] = aa;
        size[aa] += size[bb];
        S[aa] += S[bb];
        ans.insert (S[aa]);
    }
}
int main () {
    __FastIO;
    int n, m, q;
    cin >> n >> m >> q;
    init (n);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        V[i].pb (x);
    }

    map<int, int>mp;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[i].pb (pii (u, v) );
    }

    for (int i = 0; i < q; i++) {
        char ch;
        int u, val, idx;
        cin >> ch;

        if (ch == 'D') {
            cin >> idx;
            Q[i].ch = ch;
            Q[i].idx = idx;
            mp[idx] = 1;

        } else {
            cin >> u >> val;
            Q[i].ch = ch;
            Q[i].u = u;
            Q[i].val = val;
            V[u].pb (val);
        }
    }

    for (int i = 1; i <= n; i++) {
        int sz = V[i].size();
        int aa = V[i][sz - 1];
        S[i] = aa;
        ans.insert (S[i]);
    }

    for (int i = 1; i <= m; i++) {
        if (mp[i] == 0) {
            int a = edge[i][0].first;
            int b = edge[i][0].second;
            makeSet (a, b);
        }
    }

    vector<ll>v;

    for (int i = q - 1; i >= 0; i--) {
        v.pb (getSize() );
        char ch = Q[i].ch;

        if (ch == 'D') {
            int x = Q[i].idx;
            int a = edge[x][0].first;
            int b = edge[x][0].second;
            makeSet (a, b);

        } else {
            int x = Q[i].u;
            int xx = Q[i].val;
            int p = find (x);
            ll X = S[p];
            it = ans.find (X);

            if (it != ans.end() ) {
                ans.erase (it);
            }

            V[x].pop_back();
            int sz = V[x].size();
            S[p] -= (ll) xx;
            S[p] += (ll) V[x][sz - 1];
            ans.insert (S[p]);
        }
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << "\n";
    }

    return 0;
}
