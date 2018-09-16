/***************************************************
 * Problem Name : D. Edges in MST.cpp
 * Problem Link : http://codeforces.com/contest/160/problem/D
 * OJ           : Codeforces
 * Verdict      : Trying
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
struct Edge {
    int id, u, v, w;
};
bool cmp (Edge a, Edge b) {
    return  a.w < b.w;
}
vector<Edge>E;
set<int>st;
int par[MAX];
int chk[1000005];

int find (int r) {
    if (par[r] == r) return r;
    else return par[r] = find (par[r]);
}
void MST (int n) {
    sort (all (E), cmp);

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    int cnt =  0;

    for (int i = 0; i < (int) E.size(); i++) {
        int u = find (E[i].u);
        int v = find (E[i].v);
        int W = E[i].w;

        if (u != v) {
            par[u] = v;
            cnt++;
            //~ adj[E[i].u].pb (E[i].v);
            //~ adj[E[i].v].pb (E[i].u);
            //~ cost[E[i].u].pb (E[i].w);
            //~ cost[E[i].v].pb (E[i].w);
            //~ chk[W]++;
            st.insert (W);
            //~ ans[x] = 1;
            //~ if(chk[W] == 0){

            //~ }

            if (cnt == n) break;
        }
    }
}
int main () {
    //~ __FastIO;
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        Edge get;
        cin >> get.u >> get.v >> get.w;
        get.id = i;
        chk[get.w]++;
        E.pb (get);
    }

    MST (N);
    int ans[1000005];
    SET (ans, 0);
    int cnt = 0;

    for (auto it = st.begin(); it != st.end(); it++) {
        int x = *it;
        //~ cout << x << "\n";
        //~ cout << chk[x] << "\n";
        cnt += chk[x];

        if (chk[x] == 1) {
            ans[x] = 1;

        } else {
            ans[x] = 2;
        }
    }

    int A[MAX];

    if (cnt < N) {
        for (int i = 0; i < (int) E.size(); i++) {
            int x = E[i].w;
            int X = E[i].id;
			//~ cout << ans[x]<<"\n";
            if (ans[x] == 0) {
                A[X] = 0;
            } else A[X] = 1;
        }

    } else {
        for (int i = 0; i < (int) E.size(); i++) {
            int x = E[i].w;
            int X = E[i].id;

            if (ans[x] == 1) {
                A[X] = 1;

            } else if (ans[x] == 2) {
                A[X] = 2;

            } else A[X] = 0;
        }
    }

    for (int i = 1; i <= M; i++) {
        if (A[i] == 0) {
            cout << "none\n";

        } else if (A[i] == 1) cout << "any\n";
        else cout << "at least one\n";
    }

    return 0;
}
