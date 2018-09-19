/***************************************************
 * Problem Name : C. Coffee Break.cpp
 * Problem Link :
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-09-16
 * Problem Type :
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
int main () {
    __FastIO;
    ll n, m, d;
    cin >> n >> m >> d;
    ll ar[n + 5];
    set<ll>stt;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        stt.insert (ar[i]);
    }

    int c = 1;
    map<ll, int>mp;

    while (!stt.empty() ) {
        auto it = stt.begin();
        ll x = *it;
        mp[x] = c;
        stt.erase (it);
        ll xx = x + d;
        auto up = stt.upper_bound (xx);

        while (up != stt.end() ) {
            x = *up;
            mp[x] = c;
            xx = x + d;
            stt.erase (up);
            up = stt.upper_bound (xx);
        }

        c++;
    }

    c--;
    cout << c << "\n";

    for (int i = 1; i <= n; i++) {
        cout << mp[ar[i]] << " ";
    }

    nl;
    return 0;
}
