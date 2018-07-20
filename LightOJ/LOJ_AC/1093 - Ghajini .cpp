/***************************************************
 * Problem name : 1093 - Ghajini .cpp
 * Problem Link : http://lightoj.com/volume_showproblem.php?problem=1093                       
 * OJ           : LOJ                                  
 * Verdict      : AC                
 * Date         : 19.05.2017                         
 * Problem Type :                                
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU                      
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define SET(a) memset(a,-1,sizeof(a))
#define pii pair<int,int>
#define debug printf("#########\n")
#define nl printf("\n")
#define MAX 100005
using namespace std;
typedef long long ll;
ll ar[MAX],ar_max[MAX];
ll st[MAX][16], st_max[MAX][16];
void build_st(ll n) {
    for (int i = 0; i < n; i++) st[i][0] = i;
    for (int j = 1; j <= 1 << j; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            ll x = st[i][j - 1];
            ll y = st[i + (1 << (j - 1))][j - 1];
            if (ar[x] <= ar[y]) st[i][j] = x;
            else st[i][j] = y;
        }
    }
}
int query(ll lb, ll ub) {
    ll cnt = ub - lb + 1;
    ll k = log2(cnt);
    ll x = st[lb][k];
    ll y = st[ub - (1 << k) + 1][k];
    if (ar[x] <= ar[y]) return x;
    else return y;
}
void build_st_max(ll n) {
    for (int i = 0; i < n; i++) st_max[i][0] = i;
    for (int j = 1; j <= 1 << j; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            ll x = st_max[i][j - 1];
            ll y = st_max[i + (1 << (j - 1))][j - 1];
            if (ar_max[x] >= ar_max[y]) st_max[i][j] = x;
            else st_max[i][j] = y;
        }
    }
}
int query_max(ll lb, ll ub) {
    ll cnt = ub - lb + 1;
    ll k = log2(cnt);
    ll x = st_max[lb][k];
    ll y = st_max[ub - (1 << k) + 1][k];
    if (ar_max[x] >= ar_max[y]) return x;
    else return y;
}
int main () {
    int tc;
    ll n, d;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%lld %lld", &n, &d);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &ar[i]);
            ar_max[i] = ar[i];
        }
        build_st(n);
        build_st_max(n);
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            ll x, y;
            x = i;
            y = (x + d) - 1;
            if(y>=n){
				break;
			}
            ll m = ar_max[query_max(x,y)];
            ll s = ar[query(x, y)];
            //~ printf("%lld %lld\n", m,s);
            ll ans = m - s;
            mx = max(mx,ans);
        }
        printf("Case %d: %lld\n",t,mx);
    }
    return 0;
}

