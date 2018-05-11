/***************************************************
 * Problem name : 10685 Nature.cpp
 * Problem Link : https://uva.onlinejudge.org/external/106/10685.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 11.06.2017
 * Problem Type : Union Find
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
#define MAX 5005
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
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
/************************************ Code Start Here ******************************************************/
map<string, int>mp;
int par[MAX], gm[MAX],mx;
void makeSet(int u) {
    par[u] = u;
}
int findRepresentative(int r) {
    if (par[r] == r) {
        return r;
    } else {
        par[r] = findRepresentative(par[r]);
    }
    return par[r];
}
void setUnion(int a, int b) {
    int u = findRepresentative(a);
    int v = findRepresentative(b);
    int r = gm[u];
    int rr = gm[v];
    if (u != v) {
        par[u] = v;
        int x = findRepresentative(u);
        int ans = r + rr;
        mx = max(mx,ans);
        gm[x] = ans;
    }
    mx = max(mx,rr);
}
void initUnion(int N) {
    for (int i = 1; i <= N; i++) {
        makeSet(i);
    }
}
int main () {
    int C, R;
    while (scanf("%d %d", &C, &R) == 2) {
		if(C == 0 && R == 0) {
			break;
		}
		mx = 1;
        for (int i = 1; i <= C; i++) {
            string s;
            cin >> s;
            mp[s] = i;
            gm[i] = 1;
        }
        initUnion(C);
        for (int i = 1; i <= R; i++) {
            string a , b;
            cin >> a >> b;
            setUnion(mp[a], mp[b]);
        }
        //~ int mx = 0;
        //~ for (int i = 1; i <= C; i++) {
            //~ mx = max(mx, gm[i]);
        //~ }
        printf("%d\n", mx);
        mp.clear();
        //~ nl;
    }
    return 0;
}
