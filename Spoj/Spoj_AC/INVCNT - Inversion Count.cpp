/***************************************************
 * Problem Name : INVCNT - Inversion Count.cpp
 * Problem Link : https://www.spoj.com/problems/INVCNT/
 * OJ           : Spoj
 * Verdict      : AC
 * Date         : 2018-10-02
 * Problem Type : Data Sturcture (BIT)
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
ll tree[MAX];
int getNext (int id) {
    return id + (id & -id);
}
int getPar (int id) {
    return id - (id & -id);
}
void update (int id, int n, int val) {
    while (id <= n) {
        tree[id] += val;
        id = getNext (id);
    }
}
ll query (int id) {
    ll sum = 0;

    while (id > 0) {
        sum += tree[id];
        id = getPar (id);
    }

    return sum;
}
int main () {
    __FastIO;
    int n, tc;
    ll ar[MAX];
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;
        set<ll>st;
        map<ll, int>mp;

        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
            st.insert (ar[i]);
        }

        int k = 1;

        for (auto it = st.begin(); it != st.end(); it++) {
            if (mp[*it] == 0) mp[*it] = k++;
        }

        k--;
        SET (tree, 0);
        ll sum = 0;

        for (int i = 1; i <= n; i++) {
            ll xx = query (k);
            ll x = query (mp[ar[i]]);
            sum += (xx - x);
            update (mp[ar[i]], k, 1);
        }

        cout << sum << "\n";
    }

    return 0;
}
