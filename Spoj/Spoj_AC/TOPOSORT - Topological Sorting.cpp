/***************************************************
 * Problem Name : TOPOSORT - Topological Sorting.cpp
 * Problem Link : https://www.spoj.com/problems/TOPOSORT/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-09-15
 * Problem Type : Graph - Top Sort
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
#define MAX 10005
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
vector<int>adj[MAX], order;
set<int>nextNode;
int indeg[MAX];
int cnt;
void topSort() {
    int u, v;
    cnt = 0;

    while (!nextNode.empty() ) {
        u = *nextNode.begin();
        nextNode.erase (nextNode.begin() );
        order.pb (u);
        cnt++;

        for (int i = 0; i != (int) adj[u].size(); i++) {
            v = adj[u][i];
            indeg[v]--;

            if (!indeg[v]) {
                nextNode.insert (v);
            }
        }
    }
}

int main() {
    __FastIO;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb (v);
        indeg[v] += 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) {
            nextNode.insert (i);
        }
    }

    topSort();

    if (cnt != n) {
        cout << "Sandro fails.\n";

    } else {
        for (int i = 0; i < n; i++) {
            if (i != 0) cout << " ";

            cout << order[i];
        }

        nl;
    }

    return 0;
}
