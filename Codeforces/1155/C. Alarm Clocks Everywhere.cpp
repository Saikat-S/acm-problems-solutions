/***************************************************
 * Problem Name : C. Alarm Clocks Everywhere.cpp
 * Problem Link : https://codeforces.com/contest/1155/problem/C
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-04-23
 * Problem Type : Edu - C
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
    int n, m;
    cin >> n >> m;
    ll ar[n + 3];

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    vector<ll>vec;

    for (int i = 0; i < n - 1; i++) {
        vec.pb (ar[i + 1] - ar[i]);
    }

    ll gc = vec[0];

    for (int i = 1; i < (int) vec.size(); i++) {
        gc = __gcd (gc, vec[i]);
    }

    int ans = -1;

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;

        if (gc % x == 0) {
            ans = i;
            break;
        }
    }

    if (ans == -1) {
        cout << "NO\n";

    } else {
        cout << "YES\n";
        cout << ar[0] << " " << ans + 1 << "\n";
    }

    return 0;
}
