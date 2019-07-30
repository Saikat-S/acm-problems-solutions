/***************************************************
 * Problem Name : C. Tokitsukaze and Discard Items.cpp
 * Problem Link : https://codeforces.com/contest/1191/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-12
 * Problem Type : Div 2 - C
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
#define MAX 100005
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
int main () {
    __FastIO;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll>vec (m);

    for (int i = 0; i < m; i++) {
        cin >> vec[i];
    }

    ll cnt = 0;
    ll X = k;
    ll ans = 0;

    while (1) {
        ll up = upper_bound (all (vec), X) - vec.begin();
        ll x = up - cnt;
        X += x;

        if (up == cnt) {
            up = upper_bound (all (vec), X) - vec.begin();
            ll xx = vec[up];
            xx -= X;
            ll next = xx / k;

            if (xx % k != 0) next++;

            X += next * k;
            continue;
        }

        cnt += x;
        ans++;

        if (cnt == m) break;
    }

    cout << ans << "\n";
    return 0;
}

