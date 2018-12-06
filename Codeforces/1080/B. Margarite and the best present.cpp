/***************************************************
 * Problem Name : B. Margarite and the best present.cpp
 * Problem Link : https://codeforces.com/contest/1080/problem/B
 * OJ           : Codeforces
 * Verdict      : AC
 * Date         : 2018-11-25
 * Problem Type : Div 2 - B
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
#define MAX 100005
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
ll evenNumberSum (ll l, ll r) {
    ll  R = r / 2;
    ll L = l / 2;
    ll even1 = R * (R + 1);
    ll even2 = L * (L + 1);

    if (l % 2 == 0) even2 -= l;

    ll even = even1 - even2;
    return even;
}
ll oddNumberSum (ll l, ll r) {
    ll sum = ( (r * (r + 1) ) / 2) - ( (l - 1) * l) / 2;
    ll  R = r / 2;
    ll L = l / 2;
    ll even1 = R * (R + 1);
    ll even2 = L * (L + 1);

    if (l % 2 == 0) even2 -= l;

    ll even = even1 - even2;
    ll odd = sum - even;
    return odd;
}

int main () {
    __FastIO;
    ll n, l, r;
    cin >> n;

    while (n--) {
        cin >> l >> r;
        cout << (evenNumberSum (l, r) - oddNumberSum (l, r) ) << "\n";
    }

    return 0;
}
