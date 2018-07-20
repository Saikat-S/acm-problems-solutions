/***************************************************
 * Problem name : 1174 - IP-TV.cpp
 * Problem Link : https://uva.onlinejudge.org/external/11/1174.pdf                       
 * OJ           : Uva                                  
 * Verdict      : AC                      
 * Date         : 2017-08-07                         
 * Problem Type : MST                               
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
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define pll pair <int, int>
#define debug printf("#########\n")
#define nl printf("\n")
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pb push_back
#define MAX 2005
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
struct edge {
    //~ string u,v;
    ll u, v, w;
    bool operator<(const edge &p)const {
        return w < p.w;
    }
};
map<string, ll>mp;
vector<ll>adj[MAX];
ll par[MAX], color[MAX];
vector<edge>E;
ll find(ll r) {
    if (par[r] == r) return r ;
    else return par[r]  = find(par[r]);
}
ll MST(ll n) {
    sort(E.begin(), E.end());
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    ll cnt = 0, mx = 0, sz = E.size();
    for (int i = 0; i < sz; i++) {
        ll u = find(E[i].u);
        ll v = find(E[i].v);
        if (u != v) {
            par[u] = v;
            cnt++;
            ll x = E[i].u;
            ll y = E[i].v;
            ll ww = E[i].w;
            adj[x].push_back(y);
            adj[y].push_back(x);
            mx += ww;
            //~ printf("%d %d %d\n\n", x,y,ww);
            if (cnt == n - 1) break;
        }
    }
    return mx;
}
void dfs(ll u) {
    color[u] = 1;
    ll sz = adj[u].size();
    for (int i = 0; i < sz; i++) {
        ll v = adj[u][i];
        if (color[v] == 0) {
            dfs(v);
        }
    }
}
void mem() {
    for (int i = 0; i < MAX; i++) {
        color[i] = 0;
    }
}
void Clear() {
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
        par[i] = 0;
    }
    E.clear(), mp.clear();
}
int main () {
    //~ __FastIO;
    ll n, m, tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        if (m != 0 ) {
            ll k = 1;
            //~ getchar();
            for (int i = 1; i <= m; i++) {
                 getchar();
                 //~ cin.ignore();
                string u, v;
                ll w;
                cin >> u >> v;
                cin >> w;
                if (mp[u] == 0) {
                     mp[u] = k++;
                    //~ cout << u << " " << mp[u];
                    //~ nl;
                }
                if (mp[v] == 0) {
                    mp[v] = k++;
                    //~ cout << u << " " << mp[u];
                    //~ nl;
                }
                //~ scanf("%lld %lld %lld", &u, &v, &w);
                edge get;
                get.u = mp[u];
                get.v = mp[v];
                get.w = w;
                E.push_back(get);
            }
            ll mx = MST(n);
            mem();
            dfs(1);
            int flag = 0;
            for (int i = 1; i <= n; i++) {
                if (color[i] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) cout << "Impossible\n";
            else cout << mx << "\n";
            Clear();
        } else {
            int flag = 0;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) cout << "Impossible\n";
            else cout << "0\n";
        }
        if(t != tc) nl;
    }
    return 0;
}

