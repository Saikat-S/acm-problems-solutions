/***************************************************
 * Problem Name : B. Mike and Feet.cpp
 * Problem Link : http://codeforces.com/contest/547/problem/B
 * OJ           : Codeforces
 * Verdict      : Trying
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
#define MAX 200005
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
int par[MAX], size[MAX];
bool cmp (pii a, pii b) {
    return a.first > b.first;
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

        par[b] = a;
        size[a] += size[b];
    }
}
int main () {
    __FastIO;
    int  n;
    cin >> n;
    vector<pii>v;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.pb (pii (x, i) );
    }

    sort (all (v), cmp);

    for (int i = 0; i <= n; i++) {
        par[i] = i;
        size[i] = 1;
    }

    int id = 1;
    int vis[MAX], ans[MAX];
    SET (vis, 0);

    for (int i = 0; i < n; i++) {
        int pos = v[i].second;
        vis[pos] = 1;

        if (vis[pos - 1] == 1 && pos - 1 >= 1) {
            makeSet (pos - 1, pos);
        }

        if (vis[pos + 1] == 1 && pos + 1 <= n) {
            makeSet (pos + 1, pos);
        }

        int p = find (pos);

        while (size[p] >= id) {
            ans[id] = v[i].first;
            id++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    nl;
    return 0;
}
