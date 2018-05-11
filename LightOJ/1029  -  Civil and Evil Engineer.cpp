/***************************************************
 * Problem name : 1029 - Civil and Evil Engineer.cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1029
 * OJ           : LOJ
 * Verdict      : AC
 * Date         : 2017-07-30
 * Problem Type : Graph(MST)
 * Author Name  : Saikat Sharma
 * University   : CSE,MBSTU
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
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 205
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
template <typename T>
std::string NumberToString ( T Number ) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
/************************************ Code Start Here ******************************************************/
int par[MAX];
struct edge {
    int u, v, w;
    bool operator<(const edge &p)const {
        return w < p.w;
    }
};
struct Edge {
    int u, v, w;
    bool operator<(const Edge &p)const {
        return w > p.w;
    }
};
vector<edge>e;
vector<Edge>Ed;
int find(int r) {
    return (par[r] == r) ? r : find(par[r]);
}
int MST(int n) {
    sort(e.begin(), e.end());
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    int cnt = 0, s = 0, sz = e.size();
    for (int i = 0; i < sz; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            par[u] = v;
            cnt++;
            s += e[i].w;
            if (cnt == n) break;
        }
    }
    return s;
}
int MST_MAX(int n) {
    sort(Ed.begin(), Ed.end());
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    int cnt = 0, s = 0, sz = e.size();
    for (int i = 0; i < sz; i++) {
        int u = find(Ed[i].u);
        int v = find(Ed[i].v);
        if (u != v) {
            par[u] = v;
            cnt++;
            s += Ed[i].w;
            if (cnt == n ) break;
        }
    }
    return s;
}
void Clear() {
    for (int i = 0; i < MAX; i++) {
        par[i] = 0;
 
    }
    Ed.clear(), e.clear();
}
int main () {
    //~ freopen("input.txt", "r", stdin);
    //~ freopen("output.txt", "w", stdout);
    int N, tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d", &N);
        for (int i = 0; ; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (u == v && v == w && w == 0) break;
            edge get;
            Edge Get;
            get.u = u;
            Get.u = u;
            get.v = v;
            Get.v = v;
            get.w = w;
            Get.w = w;
            e.push_back(get);
            Ed.push_back(Get);
        }
        int mn = MST(N);
        //~ printf("%d\n", mn);
        SET(par);
        int mx = MST_MAX(N);
        //~ printf("%d\n", mx);
        int sum = mn + mx;
        if (sum % 2 == 0) printf("Case %d: %d\n", t, sum / 2);
        else {
            printf("Case %d: %d/2\n", t, sum);
        }
        Clear();
    }
    return 0;
}
