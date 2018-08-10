/***************************************************
 * Problem Name : 10583 - Ubiquitous Religions.cpp
 * Problem Link : https://uva.onlinejudge.org/external/105/10583.pdf
 * OJ           : Uva
 * Verdict      : AC
 * Date         : 2018-06-01
 * Problem Type : Data Structure(DSU)
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
#define MAX 50005
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
int par[MAX];
//~ int size[MAX];
void init (int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        //~ size[i] = 1;
    }
}
int find (int r) {
    if (r == par[r]) return r;
    else return par[r] = find (par[r]);
}
void makeSet (int a, int b) {
    a = find (a);
    b = find (b);

    //~ debug;
    if (a != b) {
        //~ if (size[a] < size[b]) {
            //~ swap (a, b);
        //~ }

        par[b] = a;
        //~ size[a] += size[b];
    }
}
int main () {
    __FastIO;
    int n, m;
    int t = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        init (n);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            makeSet (a, b);
        }

        int chk[MAX], cnt = 0;
        SET (chk, 0);

        for (int i = 1; i <= n; i++) {
            int p = find (i);

            if (chk[p] == 0) {
                cnt++;
                chk[p] = 1;
            }
        }

        cout << "Case " << t++ << ": " << cnt << "\n";
    }

    return 0;
}
