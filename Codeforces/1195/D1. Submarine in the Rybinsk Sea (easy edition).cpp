/***************************************************
 * Problem Name : D1. Submarine in the Rybinsk Sea (easy edition).cpp
 * Problem Link : https://codeforces.com/contest/1195/problem/D1
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2019-07-17
 * Problem Type : Div 2 - D1
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
#define MOD 998244353
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
ll get (int n) {
    ll sum = 1;

    for (int i = 1; i < n; i++) {
        sum = (sum * 10LL) % MOD;
    }

    return sum % MOD;
}

ll  fun (ll num, ll n) {
    string str = NumberToString (num);
    ll total = 0LL;
    ll sz = (ll) str.size();
    ll tmp = 2LL * sz;

    for (int i = 0; i < (int) str.size(); i++) {
        ll x = str[i] - '0';
        ll val = tmp;

        for (int j = 0; j < 2; j++) {
            ll xx = ( (x * n) % MOD * get (val) % MOD) % MOD;
            total = (total % MOD + xx % MOD) % MOD;
            val--;
        }

        tmp -= 2;
    }

    return total % MOD;
}


int main () {
    __FastIO;
    int n;
    cin >> n;
    int *ar = (int *) calloc (n, sizeof (int) );

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        ll xx = fun (ar[i], n);
        sum = (sum + xx) % MOD;
    }

    cout << sum << "\n";
    return 0;
}
