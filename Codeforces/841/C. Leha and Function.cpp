/***************************************************
 * Problem Name : C. Leha and Function.cpp
 * Problem Link : https://codeforces.com/contest/841/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-06-04
 * Problem Type : Div 2 - A
 * Author Name  : Saikat Sharma
 * University   : CSE, MBSTU
 ***************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
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
#define __FileRead freopen ("input.txt", "r", stdin);
#define __FileWrite freopen ("output.txt", "w", stdout);
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
#define MOD 1000000007
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

//~ ll numSub (ll n, ll k) {
//~ ll x = (n - k) + 1LL;
//~ return (x * ( x + 1LL) ) / 2LL;
//~ }

//~ double F (ll n, ll k) {
//~ ll x = (n - k) + 1LL;
//~ ll xx = (x * ( x + 1LL) ) / 2LL;
//~ ll sum = 0;

//~ for (int i = 1; x != 0; i++) {
//~ sum += (i * x);
//~ x--;
//~ }

//~ double ans = (double) sum / (double) xx;
//~ return ans;
//~ }


int main () {
    __FastIO;
    //~ cout << setprecision (15) << fixed;
    //~ double ans = F(7, 2);
    //~ cout << ans << "\n";
    ll m, ar[MAX], br[MAX];
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> ar[i];
    }

    vector<pii>vec;

    for (int i = 0; i < m; i++) {
        cin >> br[i];
        vec.pb (pii (br[i], i) );
    }

    sort (ar, ar + m);
    sort (all (vec) );
    int ans[MAX];

    for (int i = 0, j = m - 1; i < m; i++) {
        int pos = vec[i].second;
        ans[pos] = ar[j--];
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }

    nl;
    //~ double sum = 0.;
    //~ for (int i = 0; i < m; i++) {
    //~ sum += F (ar[i], br[i]);
    //~ }
    //~ cout << sum << "\n";
    return 0;
}
